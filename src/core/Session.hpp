#pragma once
#include <string>
#include <fstream>
#include <iostream>

#include "database.hpp"

struct Session {
public:
    std::string userEmail {""};
    Database database {};

    Session();
    ~Session();

    void loadOrdersFile();
    void saveOrdersFile();

    void printOrders(std::ostream & os);

private:
    void loadUserFile();
    void loadProductFile();

    void saveUserFile();
    void saveProductFile();
};