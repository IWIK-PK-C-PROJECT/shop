#pragma once

#include "../core/view.hpp"

class LoggedMainView : public View
{
public:
    View* display(Session&) override;
    std::string getDisplayName() override;
};