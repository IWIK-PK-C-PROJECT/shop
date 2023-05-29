#pragma once
#include "../core/view.hpp"

class LoginView : public View
{
public:
    std::unique_ptr<View> display(session&) override;
};
