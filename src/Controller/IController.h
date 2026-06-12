#pragma once

class IController
{
public:
    virtual ~IController() = default;
    virtual void handleInput() = 0;
    virtual bool isRunning() const = 0;
};
