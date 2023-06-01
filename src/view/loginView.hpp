#pragma once
#include "../core/view.hpp"

class LoginView : public View
{
public:
    View* display(session&) override;
    std::string getDisplayName() override;
};
