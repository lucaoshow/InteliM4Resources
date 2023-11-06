#include "components/buzzer.hpp"

using namespace Components;

Buzzer::Buzzer(uint8_t pin) :
pin(pin)
{
    pinMode(pin, OUTPUT);
}

void Buzzer::on()
{
    tone(pin, 440);
}

void Buzzer::off()
{
    noTone(pin);
}