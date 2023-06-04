#include "product.hpp"

std::ostream & operator<<(std::ostream & os, const Product & p)
{
    os << "- " << p.name << " | "<< p.price << " USD";
    return os;
}