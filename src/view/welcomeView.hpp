#pragma once
#include "../core/view.hpp"

class WelcomeView : public View
{
public:
    View* display(session&) override;
};
