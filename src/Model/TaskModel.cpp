#include "TaskModel.h"
#include <algorithm>

void TaskModel::addTask(const std::string& title)
{
    tasks_.emplace_back(nextId_++, title);
}

bool TaskModel::completeTask(int id)
{
    for (auto& t : tasks_)
    {
        if (t.id == id)
        {
            t.done = true;
            return true;
        }
    }
    return false;
}

bool TaskModel::deleteTask(int id)
{
    auto it = std::remove_if(tasks_.begin(), tasks_.end(),
        [id](const Task& t) { return t.id == id; });

    if (it == tasks_.end())
        return false;

    tasks_.erase(it, tasks_.end());
    return true;
}

const std::vector<Task>& TaskModel::getTasks() const
{
    return tasks_;
}
