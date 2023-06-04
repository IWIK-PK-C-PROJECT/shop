#pragma once
#include <chrono>
#include <ctime>
#include <iostream>
#include "product.hpp"

using time_point = std::chrono::time_point<std::chrono::system_clock>;
class Order
{
private:
    Product product;
    std::time_t order_date;
public:
    Order(const Product & p, const time_point & date);
    ~Order() = default;
    friend std::ostream & operator<<(std::ostream & os, const Order & o);

};



