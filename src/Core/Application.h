#pragma once
#include "../Model/TaskModel.h"
#include "../View/TaskView.h"
#include "../Controller/TaskController.h"

// Application: MVC 3요소를 생성하고 메인 루프를 구동하는 진입점.
class Application
{
public:
    void run();

private:
    TaskModel      model_;
    TaskView       view_{ model_ };
    TaskController controller_{ model_, view_ };
};
