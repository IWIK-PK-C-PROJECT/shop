#pragma once
#include "../core/view.hpp"

class LoggedMainView : public View
{
public:
    std::unique_ptr<View> display(session&) override;
};
