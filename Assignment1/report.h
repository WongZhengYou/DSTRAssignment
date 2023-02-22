#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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
vector<Vehicle> arrayvehicle();


int totalCars();
struct Invoice {
    string invoice_id,
        vehicle_title,
        registration_year,
        mileage,
        engine_size,
        url,
        invoice_date,
        price;
};

int calculateRevenue(const vector<Vehicle>& vehicles);

float calculateAveragePrice(const vector<Vehicle>& vehicles);

struct report
{
    void generateClientReport(const vector<vector<string>>& content) {
        vector<Invoice>invoices;
        vector<Vehicle>vehicles;
        // Generate report header
        cout << "---------------------- CLIENT REPORT ----------------------" << endl;
        cout << "Name:" << "" << endl;
        // Add the current date to the report header
        cout << "Date of purchase:" << "" << endl;
        cout << "--------------------- VEHICLE DETAILS ----------------------" << endl;
        cout << "Vehicle Information:" << endl;

        for (const auto& invoice : invoices) {

            //if (invoice.vehicle_title == xxx.title) {
                // Generate report body for this vehicle
                cout << "Vehicle Title:" << "" << endl;
                cout << "Vehicle Price:" << "" << endl;
                cout << "Vehicle Registration Date:" << "" << endl;
                cout << "Vehicle Fuel Type: " << "" << endl;
                cout << "Vehicle Color: " << "" << endl;
                cout << "-----------------------------------------------------------" << endl;
           // }

        }
    }
        void generateSalesReport(vector<vector<string>>&content) {
            // Generate report header
            vector<Invoice>invoices;
            vector<Vehicle>arrayvehicle;
            cout << "---------------------- SALES REPORT ----------------------" << endl;
            cout << "Total vehicles sold: " << totalCars<< endl;
            cout << "Total revenue: $" << calculateRevenue(arrayvehicle) << endl;
            cout << "Average Price of Vehicles:" << calculateAveragePrice(arrayvehicle) << endl;
            //Generate report body
            cout << "--------------------- SALES DETAILS ----------------------" << endl;
            for (auto invoice : invoices)
            {
                cout << "Invoice ID:" << invoice.invoice_id << endl;
                cout << "Date:" << invoice.invoice_date << endl;
                cout << "Total Price:$" << invoice.price << endl;
                cout << "Vehicles been sold:" << invoice.vehicle_title << endl;
            }
            //Generate report end
            cout << "-----------------------------------------------------------" << endl;
        }

        void generateBilingReport(vector<vector<string>>&content) {
            //Generate report header
            cout << "---------------------- BILLING REPORT ----------------------" << endl;
            cout << "Client Name:" << "" << endl;
            cout << "Client Information" << "" << endl;
            cout << "---------------------- VEHICLE INFORMATION ----------------------" << endl;
            cout << "Car ID" << "" << endl;
            cout << "Car Price" << "" << endl;
            cout << "Date" << "" << endl;
            //Generate report end
            cout << "-----------------------------------------------------------" << endl;

        }
    

};


//// Function to split a string into an array of strings
//vector<string> split(const string& s, char delimiter) {
//    vector<string> tokens;
//    string token;
//    istringstream tokenStream(s);
//    while (getline(tokenStream, token, delimiter)) {
//        if (!token.empty()) {  // add this line to skip empty tokens
//            tokens.push_back(token);
//        }
//    }
//    return tokens;
//}
//
//int calculateTotalData() {
//    vector<vector<string>> content;
//
//    // Open the CSV file
//    ifstream file("carlist.csv");
//
//    // Read the header row from the file
//    string header;
//    getline(file, header);
//
//    // Read the data from the file
//    string line;
//    int totalData = 0;
//    while (getline(file, line)) {
//        vector<string> row;
//        istringstream ss(line);
//        string cell;
//        while (getline(ss, cell, ',')) {
//            row.push_back(cell);
//        }
//        content.push_back(row);
//        totalData++;
//    }
//
//    file.close();
//    return totalData;
//}
//int numVehiclesSold(const vector<vector<string>>& content) {
//    int count = 0;
//    for (const auto& row : content) {
//        if (!row[11].empty()) {  // Check if the sold_date field is not empty
//            count++;
//        }
//    }
//    return count;
//}


//int report() {
//   
//    return 0;
//}
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
// 
//int readCSV( Vehicle vehicles[]) {
//    int numVehicles = 0;
//    ifstream inputFile("carlist.csv");
//    string line;
//    getline(inputFile, line);  // skip the header line
//
//    while (getline(inputFile, line)) {
//        vector<string> fields = split(line, ',');
//        if (fields.size() != 12) {  // skip rows with missing fields
//            continue;
//        }
//        vehicles[numVehicles].title = fields[0];
//        vehicles[numVehicles].price = fields[1].substr(2);
//        vehicles[numVehicles].registrationDate = fields[2];
//        vehicles[numVehicles].fuelType = fields[4];
//        vehicles[numVehicles].transmission = fields[5];
//        vehicles[numVehicles].engineSize = fields[6];
//        vehicles[numVehicles].doors = fields[7];
//        vehicles[numVehicles].color = fields[8];
//        vehicles[numVehicles].bodyType = fields[9];
//        vehicles[numVehicles].URL = fields[10];
//        vehicles[numVehicles].saleDates = fields[11];
//        numVehicles++;
//    }
//    inputFile.close();
//    return numVehicles;
//}