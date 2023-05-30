#include <iostream>
#include "util/util.hpp"
#include "core/user.hpp"
#include "core/database.hpp"
#include "core/session.hpp"

#include "view/welcomeView.hpp"

#include <fstream>

int main() {
    session currentSession;

    Product productToAdd;
    productToAdd.name = "mleko";
    productToAdd.price = 4.5;
    currentSession.database.addProduct(productToAdd);

    currentSession.loadUserFile();

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

    currentSession.saveUserFile();

    return 0;
}
