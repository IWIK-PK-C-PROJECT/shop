#pragma once
#include <string>
#include <iostream>

class Product {
public:
    enum class Status : int
    {
        Available   = 0,
        Preparation = 1
    };

    std::string name {};
    double price {};

    Status status {Status::Available};
    friend std::ostream & operator<<(std::ostream & os, const Product & p);
};


