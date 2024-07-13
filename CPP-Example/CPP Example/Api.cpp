#include "Api.hpp"
#include <cpprest/http_client.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace utility;

bool Api::CheckAppExists(const std::string& appName, const std::string& ownerId, const std::string& appSecret) {
    http_client client(U("http://localhost:8080"));
    uri_builder builder(U("/auth/initiate"));

    json::value requestData;
    requestData[U("name")] = json::value::string(utility::conversions::to_utf16string(appName));
    requestData[U("ownerId")] = json::value::string(utility::conversions::to_utf16string(ownerId));
    requestData[U("secret")] = json::value::string(utility::conversions::to_utf16string(appSecret));

    auto response = client.request(methods::POST, builder.to_string(), requestData).get();

    if (response.status_code() == status_codes::NoContent) {
        return true;
    }
    else {
        return false;
    }
}

bool Api::CheckUserExists(const std::string& username, const std::string& password, const std::string& ownerId) {
    http_client client(U("http://localhost:8080"));
    uri_builder builder(U("/auth/login"));

    json::value requestData;
    requestData[U("username")] = json::value::string(utility::conversions::to_utf16string(username));
    requestData[U("password")] = json::value::string(utility::conversions::to_utf16string(password));
    requestData[U("ownerId")] = json::value::string(utility::conversions::to_utf16string(ownerId));

    auto response = client.request(methods::POST, builder.to_string(), requestData).get();

    if (response.status_code() == status_codes::NoContent) {
        return true;
    }
    else {
        return false;
    }
}

bool Api::RegisterUser(const std::string& email, const std::string& username, const std::string& password, const std::string& license, const std::string& hwid, const std::string& ownerId) {
    http_client client(U("http://localhost:8080"));
    uri_builder builder(U("/auth/register"));

    json::value registerData;
    registerData[U("email")] = json::value::string(utility::conversions::to_utf16string(email));
    registerData[U("username")] = json::value::string(utility::conversions::to_utf16string(username));
    registerData[U("password")] = json::value::string(utility::conversions::to_utf16string(password));
    registerData[U("license")] = json::value::string(utility::conversions::to_utf16string(license));
    registerData[U("hwid")] = json::value::string(utility::conversions::to_utf16string(hwid));
    registerData[U("ownerId")] = json::value::string(utility::conversions::to_utf16string(ownerId));

    auto response = client.request(methods::POST, builder.to_string(), registerData).get();

    if (response.status_code() == status_codes::NoContent) {
        return true;
    }
    else {
        return false;
    }
}

bool Api::CheckLicense(const std::string& license, const std::string& hwid, const std::string& ownerId) {
    http_client client(U("http://localhost:8080"));
    uri_builder builder(U("/auth/login"));

    json::value loginData;
    loginData[U("license")] = json::value::string(utility::conversions::to_utf16string(license));
    loginData[U("hwid")] = json::value::string(utility::conversions::to_utf16string(hwid));
    loginData[U("ownerId")] = json::value::string(utility::conversions::to_utf16string(ownerId));

    auto response = client.request(methods::POST, builder.to_string(), loginData).get();
    auto statusCode = response.status_code();
    std::cout << "Status Code: " << statusCode << std::endl;

    if (response.status_code() == status_codes::NoContent) {
        return true;
    }
    else {
        return false;
    }
}
