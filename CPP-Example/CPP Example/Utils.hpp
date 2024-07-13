#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <regex>
#include <comutil.h>   
#include <Wbemidl.h>  
#pragma comment(lib, "wbemuuid.lib")  

using namespace std;

class Utils {
public:
    static bool ValidateInput(const string& email, const string& username, const string& password);
    static string GetHWID();
};

#endif
