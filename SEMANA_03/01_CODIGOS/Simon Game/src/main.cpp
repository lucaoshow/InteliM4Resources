#include <Arduino.h>
#include "config/config.hpp"


void setup()
{
  Serial.begin(9600);
  simon.StartGame();
}

void loop()
{

}