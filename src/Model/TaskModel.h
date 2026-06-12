#pragma once
#include "IModel.h"
#include "Task.h"
#include <vector>
#include <string>

// TaskModel: 태스크 데이터와 비즈니스 로직만 담당. View/Controller 의존 없음.
class TaskModel : public IModel
{
public:
    void addTask(const std::string& title);
    bool completeTask(int id);
    bool deleteTask(int id);

    const std::vector<Task>& getTasks() const;

private:
    std::vector<Task> tasks_;
    int               nextId_ = 1;
};
