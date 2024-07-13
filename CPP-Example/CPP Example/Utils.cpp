#include "Utils.hpp"
#include <iostream>
#include <regex>
#include <Windows.h>
#include <comutil.h>

bool Utils::ValidateInput(const string& email, const string& username, const string& password) {
    regex usernameRegex("^[a-zA-Z][a-zA-Z0-9_-]{2,15}$");
    regex emailRegex("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$");
    regex passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");

    if (!regex_match(username, usernameRegex)) {
        cout << "\nInvalid username. It must be 3-16 characters long, start with a letter, and can contain letters, numbers, underscores, and hyphens." << endl;
        return false;
    }

    if (!regex_match(email, emailRegex)) {
        cout << "\nInvalid email format." << endl;
        return false;
    }

    if (!regex_match(password, passwordRegex)) {
        cout << "\nInvalid password. It must be at least 8 characters long and include at least one uppercase letter, one lowercase letter, one number, and one special character." << endl;
        return false;
    }

    return true;
}

std::string Utils::GetHWID() {
    DWORD serialNumber = 0;
    if (GetVolumeInformationA(
        "C:\\",            // Root directory to retrieve volume information
        nullptr,           // Volume name buffer
        0,                 // Volume name buffer size
        &serialNumber,     // Volume serial number
        nullptr,           // Maximum component length
        nullptr,           // File system flags
        nullptr,           // File system name buffer
        0                  // File system name buffer size
    )) {
        return std::to_string(serialNumber);
    }
    else {
        return "Error getting HWID";
    }
}