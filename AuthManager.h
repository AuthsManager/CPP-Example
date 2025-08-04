#pragma once

#include <string>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

// Configuration
void AuthManager_SetConfig(const char* appName, const char* ownerId, const char* appSecret, const char* serverHost, int serverPort);

// Core authentication functions
bool AuthManager_CheckAppExists(const char* appName, const char* ownerId, const char* appSecret);
bool AuthManager_CheckUserExists(const char* username, const char* password, const char* ownerId);
bool AuthManager_CheckLicense(const char* license, const char* hwid, const char* ownerId);
bool AuthManager_RegisterUser(const char* email, const char* username, const char* password, const char* license, const char* hwid, const char* ownerId);

// Utility functions
bool AuthManager_ValidateInput(const char* email, const char* username, const char* password);
const char* AuthManager_GetHWID();

// Authentication interface
void AuthManager_Login();
void AuthManager_License();
void AuthManager_Register();

#ifdef __cplusplus
}
#endif