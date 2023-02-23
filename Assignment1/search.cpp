#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "searchbyYearFuel.h"
#include "report.h"


using namespace std;
const int MAX_USERS = 100;

struct Role {
    string MANAGER;
    string USER;
};

struct User {
    string username;
    string password;
    Role role;
};

User users[MAX_USERS];
int user_count = 0;

void add_user(string username, string password, Role role) {
    users[user_count].username = username;
    users[user_count].password = password;
    users[user_count].role = role;
    user_count++;
}

float calculateAveragePrice(const vector<Vehicle>& vehicles) {
    int numVehicles = 0;
    float totalRevenue = 0.0;
    for (const auto& v : vehicles) {
        int price = stoi(v.price);
        totalRevenue += price;
        numVehicles++;
    }
    return totalRevenue / numVehicles;

}
vector<Vehicle> arrayvehicle() {
    vector<Vehicle>vehicles;
    vector<vector<string>>content;
    for (const auto& row : content) {
        Vehicle v;
        v.title = row[0];
        v.price = row[1];
        v.registrationDate = row[2];
        v.mileage = row[3];
        v.fuelType = row[4];
        v.transmission = row[5];
        v.engineSize = row[6];
        v.doors = row[7];
        v.color = row[8];
        v.bodyType = row[9];
        v.URL = row[10];
        v.saleDates = row[11];
        vehicles.push_back(v);
    }
    return vehicles;
}
int calculateRevenue(const vector<Vehicle>& vehicles) {
    int totalRevenue = 0;
    for (const auto& v : vehicles) {
        int price = stoi(v.price);
        totalRevenue += price;
    }
    return totalRevenue;
}
int totalCars() {
    vector<Vehicle> vehicles = arrayvehicle();
    return vehicles.size();
}
bool login(string username, string password, Role& role) {
    if (username == "manager" && password == "manager") {
        role = Role{ "manager", "" };
        return true;
    }

    for (int i = 0; i < user_count; i++) {
        if (users[i].username == username) {
            if (users[i].password == password) {
                role = users[i].role;
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}



int main() {
    vector<vector<string>> content;

    // Open the CSV file
    ifstream file("carlist.csv");

    // Read the header row from the file
    string header;
    getline(file, header);

    // Read the data from the file
    string line;
    while (getline(file, line)) {
        vector<string> row;
        istringstream ss(line);
        string cell;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        content.push_back(row);
    }

    file.close();

    Role role;
    while (true) {
        string username;
        cout << "Enter username: ";
        cin >> username;

        if (username == "exit") {
            break;
        }

        string password;
        cout << "Enter password: ";
        cin >> password;

        if (login(username, password, role)) {
            cout << "Login successful!" << endl;
            if (role.MANAGER != "") {
                cout << "Welcome to the manager page." << endl;
            }
            else {
                cout << "Welcome to the staff page." << endl;
            }

            int choice;
            do {
                cout << "Please select an option:\n";
                cout << "1. Search\n";
                cout << "2. Create Invoice\n";
                cout << "3. Generate Report\n";
                cout << "4. Exit";
                cout << "Your choice: ";
                cin >> choice;

                switch (choice) {
                case 1: {
                    int search_choice;
                    do {
                        cout << "Please select a search option:\n";
                        cout << "1. Search by year and fuel\n";
                        cout << "2. Search by transmission and engine size\n";
                        cout << "3. Back to main menu\n";
                        cout << "Your choice: ";
                        cin >> search_choice;

                        switch (search_choice) {
                        case 1: {
                            search searchobj;
                            searchobj.searchbyYearFuelh(content);
                            break;
                        }
                        case 2: {
                            search searchobj;
                            searchobj.searchbyTransEngine(content);
                            break;
                        }
                        case 3: {
                            // Back to main menu
                            break;
                        }
                        default: {
                            cout << "Invalid choice. Please try again.\n";
                            break;
                        }
                        }
                    } while (search_choice != 3);
                    break;
                }
                case 2: {
                    // Create invoice function
                    search invoice;
                    invoice.create_invoice(content);
                    break;
                }
                case 3: {
                    string choice;
                    bool validInput = false;
                    report r;
                    while (!validInput) {
                        cout << "What report you want to generate:\n1)Sales report\n2)Client report\n3)Billing report\nMy choice is (1/2/3):";
                        cin >> choice;

                        if (choice == "1") {
                            // Generate sales report
                            validInput = true;

                            r.generateSalesReport(content);

                        }
                        else if (choice == "2") {
                            // Generate client report
                            validInput = true;

                            r.generateClientReport(content);
                        }
                        else if (choice == "3") {
                            // Generate billing report
                            validInput = true;
                            r.generateBilingReport(content);
                        }
                        else {
                            cout << "Invalid input. Please enter 1, 2, or 3.\n";
                        }
                        break;
                    }
                }
                case 4: {
                    break;
                }
                default: {
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
                }
            } while (choice != 3);
        }
        else {
            add_user(username, password, Role{ "", "staff" });
            cout << "Welcome, new user. You have been added to the system." << endl;

            int choice;
            do {
                cout << "Please select an option:\n";
                cout << "1. Search\n";
                cout << "2. Create Invoice\n";
                cout << "3. Exit\n";
                cout << "Your choice: ";
                cin >> choice;

                switch (choice) {
                case 1: {
                    int search_choice;
                    do {
                        cout << "Please select a search option:\n";
                        cout << "1. Search by year and fuel\n";
                        cout << "2. Search by transmission and engine size\n";
                        cout << "3. Back to main menu\n";
                        cout << "Your choice: ";
                        cin >> search_choice;

                        switch (search_choice) {
                        case 1: {
                            search searchobj;
                            searchobj.searchbyYearFuelh(content);
                            break;
                        }
                        case 2: {
                            search searchobj;
                            searchobj.searchbyTransEngine(content);
                            break;
                        }
                        case 3: {
                            break;
                        }
                        default: {
                            cout << "Invalid choice. Please try again.\n";
                            break;
                        }
                        }
                    } while (search_choice != 3);
                    break;
                }
                case 2: {
                    // Create invoice function
                    search invoice;
                    invoice.create_invoice(content);
                    break;
                }
                case 3: {
                    cout << "Exiting the program...\n";
                    break;
                }
                default: {
                    cout << "Invalid choice. Please try again.\n";
                    break;
                }
                }
            } while (choice != 3);
        }
    }

    return 0;
}