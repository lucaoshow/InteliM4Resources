#ifndef __SIMON_HPP__
#define __SIMON_HPP__

#include <Arduino.h>
#include <vector>
#include "components/component.hpp"
#include "components/buzzer.hpp"

namespace SimonGame
{

    class Simon
    {

        public:

        Simon(std::vector<Components::Component> &leds, std::vector<Components::Component> &buttons,
            Components::Component &resetButton, Components::Buzzer &buzzer);

        void StartGame();

        void LightLedUp(uint8_t position);

        void NextRound();

        void Verify();

        void Win();

        void Lose();

        bool CheckDefeat();

        private:
        std::vector<Components::Component> &leds;
        std::vector<Components::Component> &buttons;
        Components::Component &resetButton;
        Components::Buzzer &buzzer;
        uint8_t round;
        std::vector<uint8_t> ledOrder;
        std::vector<uint8_t> pressed;

    };

}

#endif