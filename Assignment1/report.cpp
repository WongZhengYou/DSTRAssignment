#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include"C:\\Users\\User\\Downloads\\searchbyYearFuel.h"

using namespace std;

const int MAX_VEHICLES = 2000;  // Maximum number of vehicles in the CSV file

struct Vehicle {
    string title;
    string price;
    string registrationDate;
    string mileage;
    string fuelType;
    string transmission;
    string engineSize;
    string doors;
    string color;
    string bodyType;
    string URL;
    string saleDates;
};




// Function to split a string into an array of strings
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        if (!token.empty()) {  // add this line to skip empty tokens
            tokens.push_back(token);
        }
    }
    return tokens;
}
int readCSV(const string& carlist, Vehicle vehicles[]) {
    int numVehicles = 0;
    ifstream inputFile(carlist);
    string line;
    getline(inputFile, line);  // skip the header line

    while (getline(inputFile, line)) {
        vector<string> fields = split(line, ',');
        if (fields.size() != 12) {  // skip rows with missing fields
            continue;
        }
        vehicles[numVehicles].title = fields[0];
        vehicles[numVehicles].price = fields[1].substr(2);
        vehicles[numVehicles].registrationDate = fields[2];
        vehicles[numVehicles].fuelType = fields[4];
        vehicles[numVehicles].transmission = fields[5];
        vehicles[numVehicles].engineSize = fields[6];
        vehicles[numVehicles].doors = fields[7];
        vehicles[numVehicles].color = fields[8];
        vehicles[numVehicles].bodyType = fields[9];
        vehicles[numVehicles].URL = fields[10];
        vehicles[numVehicles].saleDates = fields[11];
        numVehicles++;
    }
    inputFile.close();
    return numVehicles;
}
int numVehiclesSold(Vehicle vehicle[], int numVehicles) {
    // Create a vector to store the sold vehicles
    int count = 0;
    // Loop through all the vehicles
    for (int i = 0; i < numVehicles; i++) {
        // Check if the vehicle has been sold
        if (!vehicle[i].saleDates.empty()) {
            // Add the sold vehicle to the vector
            count++;
        }
    }
    return count;
}
int calculateRevenue(Vehicle vehicles[], int numVehicles) {
    int totalRevenue = 0;
    for (int i = 0; i < numVehicles; i++) {
        try {
            // convert the price string to an integer
            int price = stoi(vehicles[i].price);
            totalRevenue += price;
        }
        catch (const invalid_argument& e) {

        }
    }
    return totalRevenue;
}


void generateSalesReport(vector <Invoice> invoices, Vehicle vehicle[], int numVehicles) {
    // Generate report header
    cout << "---------------------- SALES REPORT ----------------------" << endl;
    cout << "Total vehicles sold: " << numVehiclesSold(vehicle, numVehicles) << endl;
    cout << "Total revenue: $" << calculateRevenue(vehicle,numVehicles) << endl;
    //Generate report body
    cout << "--------------------- SALES DETAILS ----------------------" << endl;
    for (auto invoice : invoices) {
        cout << "Invoice ID:" << invoice.invoice_id << endl;
        cout << "Date:" << invoice.invoice_date << endl;
        cout << "Total Price:$" << invoice.price << endl;
        cout << "Vehicles been sold:" << invoice.vehicle_title << endl;
    }
    //Generate report end
    cout << "-----------------------------------------------------------" << endl;
}

int main() {
    string choice;
    bool validInput = false;
    Vehicle vehicle[MAX_VEHICLES];
    int numVehicles = readCSV("C:\\Users\\User\\Desktop\\Year2 Sem2\\Data Structure(DSTR)\\Assignment\\carlist.csv", vehicle);
    while (!validInput) {
        cout << "What report you want to generate:\n1)Sales report\n2)Client report\n3)Billing report\nMy choice is (1/2/3):";
        cin >> choice;

        if (choice == "1") {
            // Generate sales report
            validInput = true;
            generateSalesReport(invoices, vehicle, numVehicles);

        }
        else if (choice == "2") {
            // Generate client report
            validInput = true;

        }
        else if (choice == "3") {
            // Generate billing report
            validInput = true;
        }
        else {
            cout << "Invalid input. Please enter 1, 2, or 3.\n";
        }
    }
    return 0;
}
//// calculate total revenue and number of vehicles sold
//double totalRevenue = 0;
//int numVehiclesSold = 0;
//for (auto invoice : invoices) {
//    totalRevenue += invoice.price;
//    numVehiclesSold += invoice.vehicle_title.size();
//}
//// sort the invoices by date before generating the sales report
//sort(invoices.begin(), invoices.end(), [](const Invoice& a, const Invoice& b) {
//    return a.invoice_date < b.invoice_date;
//    });
//// generate report header
//cout << "---------------------- SALES REPORT ----------------------" << endl;
//cout << "Total vehicles sold: " << numVehiclesSold << endl;
//cout << "Total revenue: $" << fixed << setprecision(2) << totalRevenue << endl;

//// generate report body
//cout << "--------------------- SALES DETAILS ----------------------" << endl;
//for (auto invoice : invoices) {
//    cout << "Invoice ID: " << invoice.invoice_id << endl;
//    cout << "Date: " << invoice.invoice_date << endl;
//    cout << "Total price: $" << fixed << setprecision(2) << invoice.price << endl;
//    cout << "Vehicles sold:" << endl;
//    for (auto vehicle : invoice.vehicle_title) {
//        cout << "    " << invoice.vehicle_title << endl;
//    }
//    cout << endl;
//}

//// generate report footer
//cout << "-----------------------------------------------------------" << endl;
