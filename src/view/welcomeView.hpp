#pragma once
#include "../core/view.hpp"

class WelcomeView : public View
{
public:
    std::unique_ptr<View> display(session&) override;
};
