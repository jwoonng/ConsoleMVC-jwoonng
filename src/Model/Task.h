#pragma once
#include <string>

struct Task
{
    int         id;
    std::string title;
    bool        done;

    Task(int id, std::string title)
        : id(id), title(std::move(title)), done(false) {}
};
