#include "Api.hpp"
#include "Utils.hpp"
#include "Config.hpp"
#include <iostream>

bool Api::CheckAppExists(const std::string& appName, const std::string& ownerId, const std::string& appSecret) {
    std::vector<std::pair<std::string, std::string>> data = {
        {"name", appName},
        {"ownerId", ownerId},
        {"secret", appSecret}
    };
    
    std::string jsonData = Utils::CreateJsonString(data);
    int statusCode = Utils::SendHttpPost(server_host, server_port, "/auth/initiate", jsonData);
    
    return statusCode == 204; // NoContent
}

bool Api::CheckUserExists(const std::string& username, const std::string& password, const std::string& ownerId) {
    std::vector<std::pair<std::string, std::string>> data = {
        {"username", username},
        {"password", password},
        {"ownerId", ownerId}
    };
    
    std::string jsonData = Utils::CreateJsonString(data);
    int statusCode = Utils::SendHttpPost(server_host, server_port, "/auth/login", jsonData);
    
    return statusCode == 204; // NoContent
}

bool Api::RegisterUser(const std::string& email, const std::string& username, const std::string& password, const std::string& license, const std::string& hwid, const std::string& ownerId) {
    std::vector<std::pair<std::string, std::string>> data = {
        {"email", email},
        {"username", username},
        {"password", password},
        {"license", license},
        {"hwid", hwid},
        {"ownerId", ownerId}
    };
    
    std::string jsonData = Utils::CreateJsonString(data);
    int statusCode = Utils::SendHttpPost(server_host, server_port, "/auth/register", jsonData);
    
    return statusCode == 204; // NoContent
}

bool Api::CheckLicense(const std::string& license, const std::string& hwid, const std::string& ownerId) {
    std::vector<std::pair<std::string, std::string>> data = {
        {"license", license},
        {"hwid", hwid},
        {"ownerId", ownerId}
    };
    
    std::string jsonData = Utils::CreateJsonString(data);
    int statusCode = Utils::SendHttpPost(server_host, server_port, "/auth/login", jsonData);
    std::cout << "Status Code: " << statusCode << std::endl;
    
    return statusCode == 204; // NoContent
}