#include <iostream>
#include <string>
#include "Auth.hpp"
#include "Api.hpp"
#include "Config.hpp"

using namespace std;

int main() {

    if (!Api::CheckAppExists(app_name, ownerid, app_secret)) {
        cout << "App does not exist. Exiting..." << endl;
        return 0;
    }

    while (true) {
        cout << "1. Login (Username, Password)" << endl;
        cout << "2. Login (License)" << endl;
        cout << "3. Register (Email, Username, Password, License)" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Choose an option: ";

        string option;
        cin >> option;

        if (option == "1") {
            Auth::Login();
        }
        else if (option == "2") {
            Auth::License();
        }
        else if (option == "3") {
            Auth::Register();
        }
        else if (option == "4") {
            cout << "Exiting ..." << endl;
            break;
        }
        else {
            cout << "\nInvalid option. Please try again." << endl;
        }
    }

    return 0;
}