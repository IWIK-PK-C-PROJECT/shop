#pragma once

#include "../core/view.hpp"

class ProductListView : public View
{
public:
    View* display(Session&) override;
    std::string getDisplayName() override;
};