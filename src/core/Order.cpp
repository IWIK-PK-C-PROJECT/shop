#include "Order.h"

Order::Order(const Product & p, const time_point & date) : product(p), order_date(std::chrono::system_clock::to_time_t(date))
{}

std::ostream & operator<<(std::ostream & os, const Order & o)
{
    os << std::ctime(&(o.order_date)) << " " << o.product;
    return os;
}
