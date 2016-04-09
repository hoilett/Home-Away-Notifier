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

void setup()
{
  Serial.begin(115200);
  pinMode(LEDPin, OUTPUT);   //The LED of the Arduino

  lcd.begin (20,4);  //Size of LCD
 
// Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();                // go home
}

void loop()
{
}


/*
 * detects a knock
 * reports to the knocker that the occupant is not home
 * indicates to the knocker that the occupant will be contacted distantly
 * occupant can respond
 * if occupant does not repond, prompts knocker to leave a message
 */
