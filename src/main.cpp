#include <iostream>
#include "util/util.hpp"
#include "core/user.hpp"
#include "core/database.hpp"
#include "core/session.hpp"

#include "view/welcomeView.hpp"

int main() {
    session currentSession;

    User admin;
    admin.email = "admin@admin.pl";
    admin.name = "admin";
    admin.surname = "admin";
    admin.password = "haslo";
    currentSession.database.addUser(admin);

    View* currentView = new WelcomeView();
    while(true)
    {
        if(currentView == nullptr)
            return 0;

        //currentView = currentView->display(currentSession);
        View* nextView = currentView->display(currentSession); // only for clean-up
        delete currentView; // only for clean-up
        currentView = nextView; // only for clean-up
    }

    delete currentView;
    return 0;
}
