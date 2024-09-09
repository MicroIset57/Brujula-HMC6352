#include "hmc6352.h"

hmc6352 Compass(0x21);

void setup()
{
  Serial.begin(115200);
  Serial.println("Lectura del modulo compass HMC6352");
  Wire.begin(27, 26);
  Compass.begin();
  delay(1000);
}

void loop()
{
  if (0 == Compass.askHeading())
  {
    float heading = Compass.readHeading();
    Serial.print("Degree : ");
    Serial.println(heading / 10.0);
  }
  delay(100);
}
