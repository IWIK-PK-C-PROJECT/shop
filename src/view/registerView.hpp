#pragma once
#include "../core/view.hpp"

class RegisterView : public View
{
public:
    View* display(session&) override;
    std::string getDisplayName() override;
};
