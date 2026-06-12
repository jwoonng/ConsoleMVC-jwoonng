#pragma once
#include "IView.h"
#include "../Model/TaskModel.h"
#include <string>

// TaskView: 콘솔 출력 전담. 데이터 가공 없이 Model에서 읽어 렌더링만 수행.
class TaskView : public IView
{
public:
    explicit TaskView(const TaskModel& model);

    void render() override;
    void showMenu() const;
    void showMessage(const std::string& msg) const;
    void showError(const std::string& msg) const;

    int         promptInt(const std::string& prompt) const;
    std::string promptString(const std::string& prompt) const;

private:
    const TaskModel& model_;
};
