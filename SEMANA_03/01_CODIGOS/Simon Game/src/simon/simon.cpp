#include "simon/simon.hpp"

using namespace SimonGame;

Simon::Simon(std::vector<Components::Component> &leds,
            std::vector<Components::Component> &buttons,
            Components::Component &resetButton,
            Components::Buzzer &buzzer) : leds(leds), buttons(buttons), resetButton(resetButton), buzzer(buzzer)
{

}

void Simon::StartGame()
{
    ledOrder.clear();
    pressed.clear();
    NextRound();
}

void Simon::LightLedUp(uint8_t position)
{
    leds[position].on();
    delay(700);
    leds[position].off();
}

void Simon::NextRound()
{
    ledOrder.push_back(random(0,3));
    pressed.clear();

    for(uint8_t i; i < ledOrder.size(); i++)
    {
        delay(500);
        LightLedUp(ledOrder[i]);
    }

    Verify();
}

void Simon::Verify()
{
    uint8_t buttonIndex = 0;
    while (pressed.size() != ledOrder.size()) 
    {
        if (buttonIndex == 4)
        {
            buttonIndex = 0;
        }

        if (buttons[buttonIndex].read())
        {
            pressed.push_back(buttonIndex);
            delay(500);
        }

        if (CheckDefeat() || resetButton.read())
        {
            Lose();
        }

        buttonIndex++;
    }

    if (!CheckDefeat())
    {
        if(pressed.size() == 4)
        {
            Win();
        }
        else
        {
            NextRound();
        }
    }
}

bool Simon::CheckDefeat()
{
    for(uint8_t i; i < pressed.size(); i++)
        {
            if (pressed[i] != ledOrder[i])
            {
                return true;
            }
        }
    return false;
}

void Simon::Lose()
{
    for(uint8_t l; l < leds.size(); l++)
    {
        leds[l].on();
    }

    buzzer.on();
    delay(1500);

    for(uint8_t l; l < leds.size(); l++)
    {
        leds[l].off();
    }

    buzzer.off();
    StartGame();
}

void Simon::Win()
{
    for(uint8_t l; l < leds.size(); l++)
    {
        leds[l].on();
        buzzer.on();
        delay(100);
        leds[l].off();
        buzzer.off();
    }

    for(uint8_t l; l < leds.size(); l++)
    {
        leds[l].on();
        delay(100);
    }
    
    buzzer.on();
    delay(1000);

    buzzer.off();

    for(uint8_t l; l < leds.size(); l++)
    {
        leds[l].off();
    }

    delay(500);
    buzzer.on();

    for(uint8_t l; l < leds.size(); l++)
    {
        leds[l].on();
    }

    delay(2000);
    buzzer.off();

    for(uint8_t l; l < leds.size(); l++)
    {
        leds[l].off();
    }

    StartGame();
}