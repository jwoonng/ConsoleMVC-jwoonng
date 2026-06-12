#include "TaskView.h"
#include <iostream>
#include <iomanip>

TaskView::TaskView(const TaskModel& model) : model_(model) {}

void TaskView::render()
{
    const auto& tasks = model_.getTasks();

    std::cout << "\n";
    std::cout << "+----------------------------------+\n";
    std::cout << "|  Task List (" << std::right << std::setw(3) << tasks.size() << " items)          |\n";
    std::cout << "+----------------------------------+\n";

    if (tasks.empty())
    {
        std::cout << "|  (empty)                         |\n";
    }
    else
    {
        for (const auto& t : tasks)
        {
            char status = t.done ? 'X' : ' ';
            std::cout << "| [" << std::right << std::setw(3) << t.id << "] [" << status << "] "
                      << std::left << std::setw(20) << t.title << std::right << " |\n";
        }
    }

    std::cout << "+----------------------------------+\n";
}

void TaskView::showMenu() const
{
    std::cout << "\n  [1] Add    [2] Complete    [3] Delete    [0] Quit\n";
    std::cout << "  > ";
}

void TaskView::showMessage(const std::string& msg) const
{
    std::cout << "  [OK] " << msg << "\n";
}

void TaskView::showError(const std::string& msg) const
{
    std::cout << "  [ERR] " << msg << "\n";
}

int TaskView::promptInt(const std::string& prompt) const
{
    int val = 0;
    std::cout << "  " << prompt;
    std::cin >> val;
    std::cin.ignore();
    return val;
}

std::string TaskView::promptString(const std::string& prompt) const
{
    std::string val;
    std::cout << "  " << prompt;
    std::getline(std::cin, val);
    return val;
}
