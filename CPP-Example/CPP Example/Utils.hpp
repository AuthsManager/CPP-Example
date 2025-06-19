#ifndef UTILS_HPP
#define UTILS_HPP

#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <sstream>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "wbemuuid.lib")  

using namespace std;

class Utils {
public:
    static bool ValidateInput(const string& email, const string& username, const string& password);
    static string GetHWID();
    static string CreateJsonString(const vector<pair<string, string>>& data);
    static int SendHttpPost(const string& host, int port, const string& path, const string& jsonData);
};

#endif