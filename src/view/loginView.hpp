#pragma once

#include "../core/view.hpp"

class LoginView : public View
{
public:
    View* display(Session&) override;
    std::string getDisplayName() override;
};