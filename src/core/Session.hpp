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

private:
    void loadUserFile();
    void loadProductFile();

    void saveUserFile();
    void saveProductFile();

    //TODO: Implement cart variable
};