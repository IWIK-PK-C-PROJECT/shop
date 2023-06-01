#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "database.hpp"

struct session {

    std::string userEmail {""};
    Database database {};

    void loadUserFile();
    void loadProductFile();

    void saveUserFile();
    void saveProductFile();

    //TODO: Implement cart variable
};