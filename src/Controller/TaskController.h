#pragma once
#include "IController.h"
#include "../Model/TaskModel.h"
#include "../View/TaskView.h"

// TaskController: 입력을 받아 Model을 조작하고 View를 갱신하는 조정자.
class TaskController : public IController
{
public:
    TaskController(TaskModel& model, TaskView& view);

    void handleInput() override;
    bool isRunning() const override;

private:
    void onAdd();
    void onComplete();
    void onDelete();

    TaskModel& model_;
    TaskView&  view_;
    bool       running_ = true;
};
