#pragma once

#include <string>
#include <vector>

using namespace std;

struct User {
    string username;
    string password_hash;
    string full_name;
    string address;
    string phone;
};

bool registerUser();
bool loginUser(string& username);
bool isUsernameUnique(const string& username);
string hashPassword(const string& password);
vector<User> loadUsers();