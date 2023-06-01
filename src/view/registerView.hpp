#pragma once
#include "../core/view.hpp"

class RegisterView : public View
{
public:
    View* display(Session&) override;
    std::string getDisplayName() override;
};
