/* LCD code source
ianbren. "[SOLVED] I2C LCD - Setup instructions for 16x2." Arduino
   Forum. SMF 1.1.18. Simple Machines. 23 Oct. 2012. Web.
   8 May 2013. <http://arduino.cc/forum/index.php?topic=128635.0>.
*/


//LCD
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR  0x3F  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN   3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C     lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

const uint8_t knockSensor = A0;
const uint16_t knockThreshold = 100;
boolean isHome = false;

const uint8_t isHomeLED = 2;
const uint8_t isAwayLED = 3;
const uint8_t isHomeSwitch = 4;

void setup()
{
  Serial.begin(115200);
  pinMode(LEDPin, OUTPUT);   //The LED of the Arduino

  pinMode(isHomeLED, OUTPUT);
  pinMode(isAwayLED, OUTPUT);
  pinMode(isHomeSwitch, INPUT);

  lcd.begin (20,4);  //Size of LCD
 
// Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();                // go home
}

void loop()
{
  if (analogRead(knockSensor) > knockThreshold)
  {
    printKnockMessage();
    
    if (isHome) printIsHomeMessage();
    else
    {
      printIsAwayMessage();
      sendAwayNotifier();
    }
  }
}

void printKnockMessage()
{
  Serial.println("Let me check if");
  Serial.println("Orlando's home");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Let me check if");
  lcd.setCursor(0,1);
  lcd.print("Orlando's home");
}

void printIsHomeMessage();
{
  Serial.println("Orlando's Home!");
  Serial.println("He's coming.");

  lcd.clear();
  lcd.setCursor(0,0),
  lcd.print("Orlando's Home!");
  lcd.setCursor(0,1);
  lcd.print("He's coming.");
}

void printIsAwayMessage()
{
  Serial.println("Orlando's Away!");

  lcd.clear();
  lcd.setCursor(0,0),
  lcd.print("Orlando's Away!");

  delay(1500);

  Serial.println("I will tell him");
  Serial.println("that you're here.");

  lcd.clear();
  lcd.setCursor(0,0),
  lcd.print("I will tell him");
  lcd.setCursor(0,1);
  lcd.print("that you're here.");
}


void sendAwayNotifier()
{
  println("someone's at the door");
}


/*
 * detects a knock
 * reports to the knocker that the occupant is not home
 * indicates to the knocker that the occupant will be contacted distantly
 * occupant can respond
 * if occupant does not repond, prompts knocker to leave a message
 */
