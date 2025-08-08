#pragma once

#include <string>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

// Configuration
void AuthManager_SetConfig(const char* appName, const char* ownerId, const char* appSecret); 

// Core authentication functions
bool AuthManager_CheckAppExists(const char* appName, const char* ownerId, const char* appSecret);
bool AuthManager_CheckUserExists(const char* username, const char* password, const char* ownerId);
bool AuthManager_CheckLicense(const char* license, const char* hwid, const char* ownerId);
bool AuthManager_RegisterUser(const char* username, const char* password, const char* license, const char* hwid, const char* ownerId);

// Utility functions
bool AuthManager_ValidateInput(const char* username, const char* password);
const char* AuthManager_GetHWID();

// Authentication interface
bool AuthManager_Login();
bool AuthManager_License();
bool AuthManager_Register();

#ifdef __cplusplus
}
#endif