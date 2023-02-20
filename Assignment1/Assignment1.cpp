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

// Function to split a string into an array of strings
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
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
        vehicles[numVehicles].title = fields[0];
        vehicles[numVehicles].price = fields[1];
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

int main() {
    string choice;
    bool validInput = false;
    while (!validInput) {
        cout << "What report you want to generate:\n1)Sales report\n2)Client report\n3)Billing report\nMy choice is:";
        cin >> choice;

        if (choice == "1") {
            // Generate sales report
            validInput = true;

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
    Vehicle vehicles[MAX_VEHICLES];
    int numVehicles = readCSV("C:\\Users\\User\\Desktop\\Year2 Sem2\\Data Structure(DSTR)\\Assignment\\carlist.csv", vehicles);
    // Print the data for each vehicle
    for (int i = 0; i < numVehicles; i++) {
        cout << "Title: " << vehicles[i].title << endl;
        cout << "Price: " << vehicles[i].price << endl;
        cout << "Registration Date: " << vehicles[i].registrationDate << endl;
        cout << "Mileage: " << vehicles[i].mileage << endl;
        cout << "Fuel Type: " << vehicles[i].fuelType << endl;
        cout << "Transmission: " << vehicles[i].transmission << endl;
        cout << "Engine Size: " << vehicles[i].engineSize << endl;
        cout << "Doors: " << vehicles[i].doors << endl;
        cout << "Color: " << vehicles[i].color << endl;
        cout << "Body Type: " << vehicles[i].bodyType << endl;
        cout << "URL:" << vehicles[i].URL << endl;
        cout << "Sale Dates:" << vehicles[i].saleDates << endl;
    }
    return 0;
}
    // Print the data for each vehicle
    //for (int i = 0; i < numVehicles; i++) {
    //    cout << "Title: " << vehicles[i].title << endl;
    //    cout << "Price: " << vehicles[i].price << endl;
    //    cout << "Registration Date: " << vehicles[i].registrationDate << endl;
    //    cout << "Mileage: " << vehicles[i].mileage << endl;
    //    cout << "Fuel Type: " << vehicles[i].fuelType << endl;
    //    cout << "Transmission: " << vehicles[i].transmission << endl;
    //    cout << "Engine Size: " << vehicles[i].engineSize << endl;
    //    cout << "Doors: " << vehicles[i].doors << endl;
    //    cout << "Color: " << vehicles[i].color << endl;
    //    cout << "Body Type: " << vehicles[i].bodyType << endl;
    //    cout << "URL:" << vehicles[i].URL << endl;
    //    cout << "Sale Dates:" << vehicles[i].saleDates << endl;
    //}
    //return 0;





//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <string>
//#include<vector>
//
//using namespace std;
//
//const int MAX_VEHICLES = 2000;  // Maximum number of vehicles in the CSV file
//
//struct Vehicle {
//    string title;
//    int price;
//    string registrationDate;
//    int mileage;
//    string fuelType;
//    string transmission;
//    int engineSize;
//    int doors;
//    string color;
//    string bodyType;
//    string URL;
//    string saleDates;
//};
//
//// Function to split a string into an array of strings
//vector<string> split(const string& s, char delimiter) {
//    vector<string> tokens;
//    string token;
//    istringstream tokenStream(s);
//    while (getline(tokenStream, token, delimiter)) {
//        tokens.push_back(token);
//    }
//    return tokens;
//}
//
//int readCSV(const string& carlist, Vehicle vehicles[]) {
//    int numVehicles = 0;
//    ifstream inputFile(carlist);
//
//    string line;
//    getline(inputFile, line);  // skip the header line
//
//    while (getline(inputFile, line)) {
//        vector<string> fields = split(line, ',');
//        string mileageStr = fields[3];
//        bool isMileageValid = true;
//        for (char c : mileageStr) {
//            if (!isdigit(c)) {
//                isMileageValid = false;
//                break;
//            }
//        }
//        if (!isMileageValid) {
//            cerr << "Error: invalid mileage value in line " << numVehicles + 2 << endl;
//            // Set mileage to a default value, for example -1
//            vehicles[numVehicles].mileage = -1;
//            // Continue with the next iteration of the loop
//            continue;
//        }
//        try {
//            vehicles[numVehicles].mileage = stoi(mileageStr);
//        }
//        catch (const std::invalid_argument& e) {
//            cerr << "Error: could not convert mileage to integer in line " << numVehicles + 2 << endl;
//            // Set mileage to a default value, for example -1
//            vehicles[numVehicles].mileage = -1;
//            // Continue with the next iteration of the loop
//            continue;
//        }
//        // If mileage conversion was successful, proceed with reading the rest of the fields
//        vehicles[numVehicles].title = fields[0];
//        vehicles[numVehicles].price = stoi(fields[1]);
//        vehicles[numVehicles].registrationDate = fields[2];
//        vehicles[numVehicles].fuelType = fields[4];
//        vehicles[numVehicles].transmission = fields[5];
//        vehicles[numVehicles].engineSize = stoi(fields[6]);
//        vehicles[numVehicles].doors = stoi(fields[7]);
//        vehicles[numVehicles].color = fields[8];
//        vehicles[numVehicles].bodyType = fields[9];
//        vehicles[numVehicles].URL = fields[10];
//        vehicles[numVehicles].saleDates = fields[11];
//        numVehicles++;
//    }
//    inputFile.close();
//    return numVehicles;
//}
//
//
//int main() {
//    Vehicle vehicles[MAX_VEHICLES];
//    int numVehicles = readCSV("C:\\Users\\User\\Desktop\\Year2 Sem2\\Data Structure(DSTR)\\Assignment\\carlist.csv", vehicles);
//    // Print the data for each vehicle
//    for (int i = 0; i < numVehicles; i++) {
//        cout << "Title: " << vehicles[i].title << endl;
//        cout << "Price: " << vehicles[i].price << endl;
//        cout << "Registration Date: " << vehicles[i].registrationDate << endl;
//        cout << "Mileage: " << vehicles[i].mileage << endl;
//        cout << "Fuel Type: " << vehicles[i].fuelType << endl;
//        cout << "Transmission: " << vehicles[i].transmission << endl;
//        cout << "Engine Size: " << vehicles[i].engineSize << endl;
//        cout << "Doors: " << vehicles[i].doors << endl;
//        cout << "Color: " << vehicles[i].color << endl;
//        cout << "Body Type: " << vehicles[i].bodyType << endl;
//        cout << "URL: " << vehicles[i].URL << endl;
//        cout << endl;
//    }
//    return 0;
//}
