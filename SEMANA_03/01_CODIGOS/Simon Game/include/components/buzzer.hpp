#ifndef __BUZZER_HPP__
#define __BUZZER_HPP__

#include <Arduino.h>

namespace Components
{
    class Buzzer
    {
        public:
        Buzzer(uint8_t pin);
        void on();
        void off();

        private:
        uint8_t pin;

    };

}

#endif