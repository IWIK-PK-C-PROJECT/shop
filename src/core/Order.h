#pragma once
#include <chrono>
#include <ctime>
#include <iostream>
#include "product.hpp"

using time_point = std::chrono::time_point<std::chrono::system_clock>;
class Order
{
private:
    std::string product_name;
    std::time_t order_date;
public:
    Order(const std::string & p, const time_point & date);
    Order(const std::string & p, const std::time_t & date);
    ~Order() = default;
    const std::string & getProductName()const{ return product_name; }
    const time_t & getOrderDate()const{ return order_date; }

};



