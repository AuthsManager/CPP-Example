#include <iostream>
#include <string>
#include "AuthManager.h"

using namespace std;

int main() {
    cout << "=== Authentication System ===" << endl;
    cout << "Powered by AuthManager" << endl << endl;
    
    // Configuration - You must fill these values
    string app_name = "";     // TODO: Set your app name
    string owner_id = "";     // TODO: Set your owner ID
    string app_secret = "";   // TODO: Set your app secret
    
    // Check if app exists
    if (!AuthManager_CheckAppExists(app_name.c_str(), owner_id.c_str(), app_secret.c_str())) {
        cout << "Authentication failed. Please check your configuration." << endl;
        return 1;
    }
    
    cout << "Application verified successfully!" << endl << endl;
    
    while (true) {
        cout << "=== Authentication Menu ===" << endl;
        cout << "1. Login (Username, Password)" << endl;
        cout << "2. Login (License)" << endl;
        cout << "3. Register (Email, Username, Password, License)" << endl;
        cout << "4. Show HWID" << endl;
        cout << "5. Exit" << endl << endl;
        cout << "Choose an option: ";

        string option;
        cin >> option;

        if (option == "1") {
            cout << "\n=== Login ===" << endl;
            if (AuthManager_Login()) {
                cout << "\n=== LOGIN SUCCESSFUL ===" << endl;
                cout << "Welcome! You are now authenticated." << endl;
                
                // TODO: Add your custom code here after successful login
                // Example: Show main menu, etc.
                
            } else {
                cout << "Login failed. Please try again." << endl;
            }
        }
        else if (option == "2") {
            cout << "\n=== License Verification ===" << endl;
            if (AuthManager_License()) {
                cout << "\n=== LICENSE VALID ===" << endl;
                cout << "Your license is valid! Access granted." << endl;
                
                // TODO: Add your custom code here after successful license validation
                // Example: Show main menu, etc.
                
            } else {
                cout << "Invalid license. Please check your license key." << endl;
            }
        }
        else if (option == "3") {
            cout << "\n=== Registration ===" << endl;
            if (AuthManager_Register()) {
                cout << "\n=== REGISTRATION SUCCESSFUL ===" << endl;
                cout << "Account created successfully! You can now login." << endl;
                
                // TODO: Add your custom code here after successful registration
                // Example: Show main menu, etc.
                
            } else {
                cout << "Registration failed. Please try again." << endl;
            }
        }
        else if (option == "4") {
            cout << "\n=== Hardware ID ===" << endl;
            cout << "Your HWID: " << AuthManager_GetHWID() << endl;
        }
        else if (option == "5") {
            cout << "\nExiting..." << endl;
            break;
        }
        else {
            cout << "\nInvalid option. Please try again." << endl;
        }
        
        cout << "\n" << string(40, '-') << "\n" << endl;
    }

    return 0;
}