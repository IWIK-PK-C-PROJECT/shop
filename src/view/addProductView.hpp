#pragma once

#include "../core/view.hpp"

class AddProductView : public View
{
public:
    View* display(Session&) override;
    std::string getDisplayName() override;
};