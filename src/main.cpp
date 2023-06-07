#include <iostream>
#include <fstream>

#include "core/user.hpp"
#include "core/Session.hpp"
#include "view/welcomeView.hpp"


int main()
{
    Session currentSession {};

    {
        std::fstream raport_file("raport.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);

        View * currentView = new WelcomeView();

        while (currentView != nullptr)
        {
            raport_file << currentView->getDisplayName() << "\n";

            View *nextView = currentView->display(currentSession); // only for clean-up
            delete currentView; // only for clean-up
            currentView = nextView; // only for clean-up
        }

        delete currentView;

        raport_file.close();
    }

    return 0;
}