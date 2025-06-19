# CPP AuthManager Example

A C++ application example for AuthManager.

## Prerequisites

- **Visual Studio 2019/2022** with C++ development tools
- **Windows SDK 10.0** or newer
- **Platform Toolset v143** (Visual Studio 2022) or v142 (Visual Studio 2019)

## Project Architecture

The project is organized into several modules:

- **`Config.cpp/hpp`** : Application configuration (API keys, server)
- **`Api.cpp/hpp`** : Interface for HTTP API calls
- **`Auth.cpp/hpp`** : Authentication and registration logic
- **`Utils.cpp/hpp`** : Utility functions (validation, HWID, HTTP)
- **`main.cpp`** : Application entry point

## Configuration

### 1. Server Configuration

Modify the parameters in `Config.cpp`:

```cpp
const std::string app_name = "your_app_name";
const std::string ownerid = "your_owner_id";
const std::string app_secret = "your_app_secret";
const std::string server_host = "127.0.0.1"; // or your server
const int server_port = 8080; // or your port
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
2. **Register** : Register a new user
3. **License** : License verification
4. **Exit** : Quit the application

### Usage Example

```
1. Login
2. Register
3. License
4. Exit
Choose an option: 2

Enter Email: user@example.com
Enter Username: testuser
Enter Password: MyPassword123!
Enter License: LICENSE-KEY-HERE
```

## APIs Used

The application communicates with an authentication server via HTTP POST:

- **`/auth/initiate`** : Application existence verification
- **`/auth/login`** : User login
- **`/auth/register`** : User registration
- **`/auth/license`** : License verification

## Features

### Input Validation

- **Email** : Valid email format
- **Username** : 3-16 characters, starts with a letter
- **Password** : 8+ characters with uppercase, lowercase, digit and special character

## File Structure

```
CPP-Example/
├── CPP Example/
│   ├── Api.cpp/hpp          # API Interface
│   ├── Auth.cpp/hpp         # Authentication
│   ├── Config.cpp/hpp       # Configuration
│   ├── Utils.cpp/hpp        # Utilities
│   ├── main.cpp             # Entry Point
│   ├── CPP Example.vcxproj  # Visual Studio Project
│   └── packages.config      # Package Configuration
├── CPP Example.sln          # Visual Studio Solution
└── README.md                # This file
```