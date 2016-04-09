const uint8_t knockSensor = A0;
void setup()
{
  Serial.begin(115200);
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
