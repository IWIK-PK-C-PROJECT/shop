#include <iostream>
#include "util/util.hpp"
#include "core/user.hpp"
#include "core/database.hpp"
#include "core/session.hpp"

#include "view/loginView.hpp"
#include "view/registerView.hpp"

int main() {
    std::string input;
    session currentSession;

    Database database {};
    while(true)
    {
        clearScreen();
        std::cout << "1. Login" << std::endl;
        std::cout << "2. Sign up" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cin >> input;
        if (input == "1")
        {
            LoginView loginView {};
            loginView.display(currentSession);
        }
        else if (input == "2")
        {
            RegisterView registerView {};
            registerView.display(currentSession);
        }
        else if (input == "3")
        {
            return 0;
        }
        else
        {

        }
    }

    return 0;
}
