#include <iostream>
#include "util/util.hpp"
#include "database/user.hpp"
#include "database/database.hpp"

struct UserSession
{
    std::string userEmail{};
    //TODO: Implement cart variable
};


void addUser(Database& database){
    using std::string, std::cout, std::cin, std::endl;

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
                return;
            }
            std::cout << "invalid data, please fill correct data" << std::endl;
        }
    }

}

void loginMenu(const Database& database, UserSession& session)
{
    clearScreen();

    std::string email, password;

    std::cout << "E-mail: ";
    std::cin >> email;

    std::cout << "Password: ";
    std::cin >> password;

    if(true) //TODO: Validate login data
        session.userEmail = email;
}

int main() {
    std::string input;
    UserSession currentSession;

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
            loginMenu(database, currentSession);
        }
        else if (input == "2")
        {
            addUser(database);
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
