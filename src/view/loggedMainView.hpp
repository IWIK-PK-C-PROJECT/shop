#pragma once
#include "../core/view.hpp"

class LoggedMainView : public View
{
public:
    View* display(session&) override;
};
