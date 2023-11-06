#include "components/component.hpp"

using namespace Components;

Component::Component(uint8_t pin, uint8_t mode) :
    pin(pin), isButton(mode == INPUT_PULLUP)
{
    pinMode(pin, mode);
}

bool Component::read()
{
    return digitalRead(this->pin) != this->isButton;
}

void Component::write(bool state)
{
    digitalWrite(this->pin, state);
}

void Component::on()
{
    this->write(true);
}

void Component::off()
{
    this->write(false);
}