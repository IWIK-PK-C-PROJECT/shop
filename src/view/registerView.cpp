#include <iostream>

#include "registerView.hpp"
#include "../util/util.hpp"
#include "welcomeView.hpp"

View* RegisterView::display(Session& session)
{
    using std::string, std::cout, std::cin, std::endl;

    auto& database = session.database;

    User userToAdd {};
    string check;

    while(true)
    {
        clearScreen();
        cout << "2. Sign up"<< endl << "Please give necessary info" <<endl;
        cout<< "Name:";
        cin >> userToAdd.name;
        cout << "Surname: ";
        cin >> userToAdd.surname;
        cout << "Email: ";
        cin >> userToAdd.email;
        cout <<"Password: ";
        cin >> userToAdd.password;
        cout <<"Is this data ok? [Y/N] ";
        cin >> check;
        if (check == "Y" || check == "y")
        {
            if( database.canAddUser(userToAdd))
            {
                database.addUser(userToAdd);
                std::cout << "user successfully registered" << std::endl;
                return new WelcomeView();
            }
            std::cout << "invalid data, please fill correct data" << std::endl;
        }
    }
}

std::string RegisterView::getDisplayName()
{
    return "RegisterView";
}