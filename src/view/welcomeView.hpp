#pragma once
#include "../core/view.hpp"

class WelcomeView : public View
{
public:
    View* display(Session&) override;
    std::string getDisplayName() override;
};
