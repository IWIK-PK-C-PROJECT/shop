#pragma once
#include "../core/view.hpp"

class RegisterView : public View
{
public:
    std::unique_ptr<View> display(session&) override;
};
