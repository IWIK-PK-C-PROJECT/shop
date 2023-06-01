#include <iostream>
#include "core/user.hpp"
#include "core/session.hpp"
#include "view/welcomeView.hpp"

#include <fstream>

int main()
{
    session currentSession {};

    currentSession.loadUserFile();
    currentSession.loadProductFile();

    // main loop
    {
        std::fstream file("raport.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);

        View *currentView = new WelcomeView();
        while (true) {
            if (currentView == nullptr)
                break;

            file << currentView->getDisplayName() << "\n";

            //currentView = currentView->display(currentSession);
            View *nextView = currentView->display(currentSession); // only for clean-up
            delete currentView; // only for clean-up
            currentView = nextView; // only for clean-up
        }
        delete currentView;

        file.close();
    }

    currentSession.saveUserFile();
    currentSession.saveProductFile();

    return 0;
}
