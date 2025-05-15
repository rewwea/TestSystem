#include "auth.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool registerUser() {
    User user;
    cout << "Придумайте логин: ";
    cin >> user.username;
    if (!isUsernameUnique(user.username)) {
        cout << "Логин уже существует.\n";
        return false;
    }
    string password;
    cout << "Придумайте пароль: ";
    cin >> password;
    user.password_hash = hashPassword(password);
    cin.ignore();
    cout << "Введите ФИО: ";
    getline(cin, user.full_name);
    cout << "Введите адрес: ";
    getline(cin, user.address);
    cout << "Введите телефон: ";
    getline(cin, user.phone);

    ofstream fout("users.db", ios::app);
    fout << user.username << '|' << user.password_hash << '|' << user.full_name << '|' << user.address << '|' << user.phone << '\n';
    fout.close();
    return true;
}

bool loginUser(string& username) {
    string password;
    cout << "Логин: ";
    cin >> username;
    cout << "Пароль: ";
    cin >> password;
    string hash = hashPassword(password);

    ifstream fin("users.db");
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string user, pass;
        getline(ss, user, '|');
        getline(ss, pass, '|');
        if (user == username && pass == hash) {
            return true;
        }
    }
    return false;
}

bool isUsernameUnique(const string& username) {
    ifstream fin("users.db");
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string user;
        getline(ss, user, '|');
        if (user == username)
            return false;
    }
    return true;
}

string hashPassword(const string& password) {
    int hash = 0;
    for (char c : password) hash += c;
    return to_string(hash);
}

vector<User> loadUsers() {
    vector<User> users;
    ifstream fin("users.db");
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        User user;
        getline(ss, user.username, '|');
        getline(ss, user.password_hash, '|');
        getline(ss, user.full_name, '|');
        getline(ss, user.address, '|');
        getline(ss, user.phone, '|');
        users.push_back(user);
    }
    return users;
}

