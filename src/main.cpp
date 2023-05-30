#include <iostream>
#include "util/util.hpp"
#include "core/user.hpp"
#include "core/database.hpp"
#include "core/session.hpp"

#include "view/welcomeView.hpp"

#include <fstream>

int main() {
    session currentSession;

    // load file
    {
        std::fstream usersFile;
        usersFile.open("users.txt", std::ios::in );
        if (!usersFile.good()) {
            std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
            return 0;
        }


        while (!usersFile.eof()) {
            User userToAdd;
            usersFile >> userToAdd.email;
            usersFile >> userToAdd.name;
            usersFile >> userToAdd.surname;
            usersFile >> userToAdd.password;

            if( userToAdd.email == "" or userToAdd.name == "" or userToAdd.surname == "" or userToAdd.password == "" )
                continue;

            currentSession.database.addUser(userToAdd);
        }

        usersFile.close();
    }



    // main loop
    View* currentView = new WelcomeView();
    while(true)
    {
        if(currentView == nullptr)
            break;

        //currentView = currentView->display(currentSession);
        View* nextView = currentView->display(currentSession); // only for clean-up
        delete currentView; // only for clean-up
        currentView = nextView; // only for clean-up
    }
    delete currentView;

    // save file
    std::fstream usersFile;
    usersFile.open("users.txt", std::ofstream::out | std::ofstream::trunc);
    for(User& user : currentSession.database.getAllUsers() )
    {
        usersFile << user.email << " ";
        usersFile << user.name << " ";
        usersFile << user.surname << " ";
        usersFile << user.password;
        usersFile << std::endl;
    }
    usersFile.close();

    return 0;
}
