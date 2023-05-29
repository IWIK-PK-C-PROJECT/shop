#pragma once
#include <memory>
#include "session.hpp"

class View
{
public:
    virtual ~View() = default;

    virtual std::unique_ptr<View> display(session&) = 0;
};
