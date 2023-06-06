#pragma once
#include "../core/view.hpp"

class ordersView : public View
{
public:
    View* display(Session&) override;
    std::string getDisplayName() override;
};
