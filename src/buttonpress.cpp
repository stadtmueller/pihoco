#include "buttonpress.h"
#include <iostream>

void button::shutdown()
{
    std::cout << "Shutdown" << std::endl;
}

void button::pause48h()
{
    std::cout << "Pause" << std::endl;
}

void button::masterButton()
{
    std::cout << "Master" << std::endl;
}

void button::button1Pressed()
{
    std::cout << "Button 1" << std::endl;
}

void button::button2Pressed()
{
    std::cout << "Button 2" << std::endl;
}
