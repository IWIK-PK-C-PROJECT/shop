#pragma once
#include "../core/view.hpp"

class ProductListView : public View
{
public:
    View* display(session&) override;
};
