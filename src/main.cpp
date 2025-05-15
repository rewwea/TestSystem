#include <iostream>
#include "auth.h"

using namespace std;

int main() {
    cout << "1. Регистрация\n2. Вход\nВыберите: ";
    int choice;
    cin >> choice;

    string currentUser;
    if (choice == 1) {
        if (registerUser()) {
            cout << "Успешная регистрация!\n";
        } else {
            cout << "Регистрация не удалась.\n";
        }
    } else if (choice == 2) {
        if (loginUser(currentUser)) {
            cout << "Вход выполнен. Добро пожаловать, " << currentUser << "!\n";
        } else {
            cout << "Неверный логин или пароль.\n";
        }
    } else {
        cout << "Неверный выбор.\n";
    }

    return 0;
}