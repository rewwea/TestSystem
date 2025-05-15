#pragma once

#include <string>
#include <vector>

struct User {
    std::string username;
    std::string password_hash;
    std::string full_name;
    std::string address;
    std::string phone;
};

bool registerUser();
bool loginUser(std::string& username);
bool isUsernameUnique(const std::string& username);
std::string hashPassword(const std::string& password);
std::vector<User> loadUsers();