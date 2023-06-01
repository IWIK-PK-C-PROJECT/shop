#include <iostream>
#include "core/user.hpp"
#include "core/session.hpp"
#include "view/welcomeView.hpp"

int main()
{
    session currentSession {};

    /*currentSession.loadUserFile();
    currentSession.loadProductFile();

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
    currentSession.saveProductFile();
*/
    return 0;
}
