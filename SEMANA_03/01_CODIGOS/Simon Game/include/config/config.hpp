#ifndef __CFG_HPP__
#define __CFG_HPP__

#include <Arduino.h>
#include <vector>
#include "components/component.hpp"
#include "components/buzzer.hpp"
#include "simon/simon.hpp"


Components::Component yellowLed(4, OUTPUT);

Components::Component redLed(16, OUTPUT);

Components::Component greenLed(17, OUTPUT);

Components::Component blueLed(18, OUTPUT);

Components::Component resetButton(27, INPUT_PULLUP);

Components::Component yellowButton(26, INPUT_PULLUP);

Components::Component redButton(25, INPUT_PULLUP);

Components::Component greenButton(33, INPUT_PULLUP);

Components::Component blueButton(32, INPUT_PULLUP);

Components::Buzzer buzzer(13);

std::vector<Components::Component> buttons = 
{
  yellowButton,
  redButton,
  greenButton,
  blueButton
};

std::vector<Components::Component> leds = 
{
  yellowLed,
  redLed,
  greenLed,
  blueLed
};

SimonGame::Simon simon(leds, buttons, resetButton, buzzer);

#endif