#include "Application.h"
#include <iostream>

void Application::run()
{
    std::cout << "========================================\n";
    std::cout << "   ConsoleMVC - Task Manager (PoC)\n";
    std::cout << "========================================\n";

    while (controller_.isRunning())
    {
        controller_.handleInput();
    }

    std::cout << "\nGoodbye!\n";
}
