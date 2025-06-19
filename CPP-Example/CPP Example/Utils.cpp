#include "Utils.hpp"

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

string Utils::GetHWID() {
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
        return to_string(serialNumber);
    }
    else {
        return "Error getting HWID";
    }
}

string Utils::CreateJsonString(const vector<pair<string, string>>& data) {
    ostringstream json;
    json << "{";
    for (size_t i = 0; i < data.size(); ++i) {
        json << "\"" << data[i].first << "\":\"" << data[i].second << "\"";
        if (i < data.size() - 1) json << ",";
    }
    json << "}";
    return json.str();
}

int Utils::SendHttpPost(const string& host, int port, const string& path, const string& jsonData) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        return -1;
    }

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        WSACleanup();
        return -1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, host.c_str(), &serverAddr.sin_addr);

    if (connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    ostringstream request;
    request << "POST " << path << " HTTP/1.1\r\n";
    request << "Host: " << host << ":" << port << "\r\n";
    request << "Content-Type: application/json\r\n";
    request << "Content-Length: " << jsonData.length() << "\r\n";
    request << "Connection: close\r\n";
    request << "\r\n";
    request << jsonData;

    string requestStr = request.str();
    send(sock, requestStr.c_str(), requestStr.length(), 0);

    char buffer[1024];
    int bytesReceived = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytesReceived] = '\0';

    closesocket(sock);
    WSACleanup();

    string response(buffer);
    size_t statusPos = response.find(" ");
    if (statusPos != string::npos) {
        string statusCode = response.substr(statusPos + 1, 3);
        return stoi(statusCode);
    }

    return -1;
}