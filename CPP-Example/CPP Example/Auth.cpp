#include "Auth.hpp"
#include "Api.hpp"
#include "Utils.hpp"
#include <iostream>
#include "Config.hpp"

void Auth::Login() {
    std::string username, password;
    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;

    bool userExists = Api::CheckUserExists(username, password, ownerid);
    std::cout << (userExists ? "User exists." : "User doesn't exist.") << std::endl;

    if (userExists) {
        std::cout << "\nPerforming actions for existing user..." << std::endl;
        // CODE HERE
    }
}

void Auth::License() {
    std::string license;
    std::cout << "Enter License: ";
    std::cin >> license;

    std::string hwid = Utils::GetHWID();

    bool licenseIsValid = Api::CheckLicense(license, hwid, ownerid);
    std::cout << (licenseIsValid ? "License is valid." : "License is invalid.") << std::endl;

    if (licenseIsValid) {
        std::cout << "\nPerforming actions for valid license..." << std::endl;
        // CODE HERE
    }
}

void Auth::Register() {
    std::string email, username, password, license;
    std::cout << "Enter Email: ";
    std::cin >> email;
    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;
    std::cout << "Enter License: ";
    std::cin >> license;

    if (!Utils::ValidateInput(email, username, password)) {
        std::cout << "Invalid input. Please check your email, username, and password and try again." << std::endl;
        return;
    }

    std::string hwid = Utils::GetHWID();

    bool registrationSuccess = Api::RegisterUser(email, username, password, license, hwid, ownerid);

    if (registrationSuccess) {
        std::cout << "\nRegistration successful." << std::endl;
        // CODE HERE
    }
    else {
        std::cout << "\nError during registration." << std::endl;
    }
}