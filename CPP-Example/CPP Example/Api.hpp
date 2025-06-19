#ifndef API_HPP
#define API_HPP

#include <string>
#include <vector>

class Api {
public:
    static bool CheckAppExists(const std::string& appName, const std::string& ownerId, const std::string& appSecret);
    static bool CheckUserExists(const std::string& username, const std::string& password, const std::string& ownerId);
    static bool CheckLicense(const std::string& license, const std::string& hwid, const std::string& ownerId);
    static bool RegisterUser(const std::string& email, const std::string& username, const std::string& password, const std::string& license, const std::string& hwid, const std::string& ownerId);
};

#endif // API_HPP