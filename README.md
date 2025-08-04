# CPP AuthManager Example

A C++ application example using the AuthManager library for authentication.

## Prerequisites

- **Visual Studio 2019/2022** with C++ development tools
- **Windows SDK 10.0** or newer
- **Platform Toolset v143** (Visual Studio 2022) or v142 (Visual Studio 2019)

## Project Architecture

The project is now organized in a simplified manner:

- **`AuthManager.h`** : AuthManager library interface (C API)
- **`CPP-Library.lib`** : Static library containing all authentication logic
- **`CPP Example.cpp`** : Example application entry point

## Configuration

### 1. Server Configuration

Modify the parameters in `CPP Example.cpp`:

```cpp
// Configuration - You must fill these values
string app_name = "your_app_name";     // TODO: Set your app name
string owner_id = "your_owner_id";     // TODO: Set your owner ID
string app_secret = "your_app_secret"; // TODO: Set your app secret
```

### 2. Visual Studio Configuration

The project is configured for:
- **Platform** : x64 (recommended)
- **Configuration** : Debug/Release
- **Character Set** : Unicode
- **C++ Standard** : C++17 or newer

## Compilation

### Via IDE

1. Open `CPP Example.sln`
2. Select **Debug** or **Release** configuration
3. Select **x64** platform
4. Press **F5** to compile and run

### Via CLI

```bash
# From the CPP-Example folder
msbuild "CPP Example.sln" /p:Configuration=Release /p:Platform=x64
```

## Usage

The application offers an interactive menu with the following options:

1. **Login** : Authentication with username/password
2. **License** : License verification
3. **Register** : Register a new user
4. **Show HWID** : Display hardware identifier
5. **Exit** : Quit the application

### Usage Example

```
=== Authentication Menu ===
1. Login (Username, Password)
2. Login (License)
3. Register (Username, Password, License)
4. Show HWID
5. Exit

Choose an option: 3

=== Registration ===
Enter Username: testuser
Enter Password: MyPassword123!
Enter License: LICENSE-KEY-HERE

=== REGISTRATION SUCCESSFUL ===
Account created successfully! You can now login.
```

## AuthManager API

The AuthManager library provides the following functions:

### Configuration
- **`AuthManager_SetConfig`** : Configure connection parameters

### Core Authentication Functions
- **`AuthManager_CheckAppExists`** : Verify application existence
- **`AuthManager_CheckUserExists`** : Verify user existence
- **`AuthManager_CheckLicense`** : Verify a license
- **`AuthManager_RegisterUser`** : Register a new user

### Utility Functions
- **`AuthManager_ValidateInput`** : Validate user inputs
- **`AuthManager_GetHWID`** : Get hardware identifier

### Authentication Interface
- **`AuthManager_Login`** : Interactive login interface
- **`AuthManager_License`** : Interactive license verification interface
- **`AuthManager_Register`** : Interactive registration interface

## Features

### Input Validation

- **Username** : 3-16 characters, starts with a letter
- **Password** : 8+ characters with uppercase, lowercase, digit and special character

### Security

- **HWID** : Hardware identification for copy protection
- **Secure Communication** : HTTP POST requests to authentication server

## File Structure

```
CPP-Example/
├── AuthManager.h            # Library interface
├── CPP Example.cpp          # Example application
├── CPP-Library.lib          # AuthManager static library
├── CPP Example.vcxproj      # Visual Studio project
├── CPP Example.vcxproj.filters # Project filters
├── CPP Example.sln          # Visual Studio solution
└── README.md                # This file
```

## Integration in Your Project

To use AuthManager in your own project:

1. Copy `AuthManager.h` and `CPP-Library.lib` to your project
2. Add `AuthManager.h` to your includes
3. Link `CPP-Library.lib` in your project settings
4. Use AuthManager functions in your code

```cpp
#include "AuthManager.h"

int main() {
    // Check app existence
    if (AuthManager_CheckAppExists("app", "owner", "secret")) {
        // Use authentication functions
        AuthManager_Login();
    }
    return 0;
}
```