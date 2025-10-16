#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Temp {
    string username, Email, password;
    fstream file;

public:
    void Login();
    void Signup();
    void Forgot();
} obj;

int main() {
    int choice;
    while (true) {
        cout << "\n1. Login";
        cout << "\n2. Sign-Up";
        cout << "\n3. Forgot Password";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                obj.Login();
                break;
            case 2:
                obj.Signup();
                break;
            case 3:
                obj.Forgot();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid selection...!\n";
        }
    }
}

void Temp::Signup() {
    cout << "\nEnter your name: ";
    getline(cin, username);
    cout << "Enter your Email Address: ";
    getline(cin, Email);
    cout << "Enter your password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << username << "*" << Email << "*" << password << "\n";
    file.close();

    cout << "Signup successful!\n";
}

void Temp::Login() {
    string searchName, searchPass;
    cout << "\n---- LOGIN ----\n";
    cout << "Enter your username: ";
    getline(cin, searchName);
    cout << "Enter your password: ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    bool found = false;

    while (getline(file, username, '*')) {
        getline(file, Email, '*');
        getline(file, password, '\n');

        if (username == searchName && password == searchPass) {
            cout << "\nAccount login successful!";
            cout << "\nUsername: " << username;
            cout << "\nEmail: " << Email << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Invalid username or password!\n";
}

void Temp::Forgot() {
    string searchName, searchEmail;
    cout << "\nEnter your username: ";
    getline(cin, searchName);
    cout << "Enter your Email Address: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    bool found = false;

    while (getline(file, username, '*')) {
        getline(file, Email, '*');
        getline(file, password, '\n');

        if (username == searchName && Email == searchEmail) {
            cout << "Account found!\n";
            cout << "Your password: " << password << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Account not found!\n";
}
