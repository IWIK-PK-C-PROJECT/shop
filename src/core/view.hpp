#pragma once
#include <memory>
#include "Session.hpp"

class View
{
public:
    virtual ~View() = default;
    virtual View* display(Session&) = 0;

    virtual std::string getDisplayName() = 0;
};
