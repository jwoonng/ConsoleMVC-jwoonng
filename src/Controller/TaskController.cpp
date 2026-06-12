#include "TaskController.h"
#include <iostream>

TaskController::TaskController(TaskModel& model, TaskView& view)
    : model_(model), view_(view) {}

void TaskController::handleInput()
{
    view_.render();
    view_.showMenu();

    int choice = 0;
    std::cin >> choice;
    std::cin.ignore();

    switch (choice)
    {
    case 1:  onAdd();             break;
    case 2:  onComplete();        break;
    case 3:  onDelete();          break;
    case 0:  running_ = false;    break;
    default: view_.showError("Unknown command. Please enter 0~3."); break;
    }
}

bool TaskController::isRunning() const
{
    return running_;
}

void TaskController::onAdd()
{
    std::string title = view_.promptString("Task title: ");
    if (title.empty())
    {
        view_.showError("Title cannot be empty.");
        return;
    }
    model_.addTask(title);
    view_.showMessage("Task added.");
}

void TaskController::onComplete()
{
    int id = view_.promptInt("Task ID to complete: ");
    if (model_.completeTask(id))
        view_.showMessage("Task #" + std::to_string(id) + " marked as done.");
    else
        view_.showError("Task #" + std::to_string(id) + " not found.");
}

void TaskController::onDelete()
{
    int id = view_.promptInt("Task ID to delete: ");
    if (model_.deleteTask(id))
        view_.showMessage("Task #" + std::to_string(id) + " deleted.");
    else
        view_.showError("Task #" + std::to_string(id) + " not found.");
}
