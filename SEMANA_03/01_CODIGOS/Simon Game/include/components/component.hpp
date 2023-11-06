#ifndef __COMPONENT_HPP__
#define __COMPONENT_HPP__

#include <Arduino.h>

namespace Components
{
    class Component
    {
        public:
        Component(uint8_t pin, uint8_t mode);
        bool read();
        void write(bool state);
        void on();
        void off();

        private:
        uint8_t pin;
        bool isButton;

    };

}

#endif