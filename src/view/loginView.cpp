#include "loginView.hpp"

#include <iostream>
#include "../util/util.hpp"

std::unique_ptr<View> LoginView::display(session& session)
{
    auto& database = session.database;

    std::string email, password;
    while(true)
    {
        clearScreen();

        std::cout << "E-mail: ";
        std::cin >> email;

        std::cout << "Password: ";
        std::cin >> password;

        if (database.isUserExist(email)) //TODO: move to user session
        {
            auto user = database.getUser(email);
            if (user.password == password) {
                session.userEmail = email;
                return {};
            }
        }
    }
}
