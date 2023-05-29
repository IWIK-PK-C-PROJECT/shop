#include <iostream>
#include "util/util.hpp"
#include "core/user.hpp"
#include "core/database.hpp"
#include "core/session.hpp"

#include "view/welcomeView.hpp"

int main() {
    session currentSession;
    std::unique_ptr<View> currentView = std::make_unique<WelcomeView>();
    while(true)
    {
        if(!currentView)
            return 0;

        currentView = currentView->display(currentSession);
    }
    return 0;
}
