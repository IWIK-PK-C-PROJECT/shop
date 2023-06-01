#pragma once
#include <string>

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
};


