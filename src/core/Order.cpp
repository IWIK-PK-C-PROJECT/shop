#include "Order.h"

Order::Order(const std::string & p, const time_point & date) : product_name(p), order_date(std::chrono::system_clock::to_time_t(date))
{}

Order::Order(const std::string & p, const std::time_t & date) : product_name(p), order_date(date)
{}