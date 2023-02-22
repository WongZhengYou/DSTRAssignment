#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct search {
    void searchbyYearFuelh(const vector<vector<string>>& content) {
        int start_year, end_year;
        string fuel_type;
        cout << "Enter the start registration year: ";
        cin >> start_year;
        cout << "Enter the end registration year: ";
        cin >> end_year;
        cout << "Enter the fuel type: ";
        cin >> fuel_type;

        // Search for matching data
        vector<vector<string>> matching_rows;
        for (const auto& row : content) {
            int year;
            try {
                year = stoi(row[2]); // Convert year to int
            }
            catch (const invalid_argument& e) {
                // Handle the error here, e.g. print an error message and skip the row
                continue;
            }
            if (year >= start_year && year <= end_year && row[4] == fuel_type) {
                matching_rows.push_back(row);
            }
        }

        // Sort the matching rows by transmission type
        vector<string> transmission_order = { "Manual", "Automatic", "Semi-Auto" };
        vector<vector<string>> sorted_rows;
        for (const auto& transmission_type : transmission_order) {
            for (const auto& row : matching_rows) {
                if (row[5] == transmission_type) {
                    sorted_rows.push_back(row);
                }
            }
        }

        // Print the sorted results
        for (int i = 0; i < sorted_rows.size(); i++)
        {
            for (int j = 0; j < sorted_rows[i].size(); j++)
            {
                cout << sorted_rows[i][j] << ",";
            }
            cout << "\n";
        }
    }

    void searchbyTransEngine(const vector<vector<string>>& content) { // Remove "std::"
        int start_year, end_year;
        string fuel_type, transmission;
        double start_engine_size, end_engine_size;
        cout << "Enter the transmission type: ";
        cin >> transmission;
        cout << "Enter the start engine size: ";
        cin >> start_engine_size;
        cout << "Enter the end engine size: ";
        cin >> end_engine_size;

        vector<vector<string>> results;
        for (const auto& row : content) {
            int year;
            double engine_size;
            try {
                year = stoi(row[2]);
                engine_size = stod(row[6]); // Remove "std::"
            }
            catch (const invalid_argument&) {
                continue;
            }

            string row_transmission = row[5];
            if (row_transmission == transmission && engine_size >= start_engine_size && engine_size <= end_engine_size) {
                results.push_back(row);
            }
        }

        // Sort the results by engine size using bubble sort
        for (int i = 0; i < results.size(); i++) {
            for (int j = 0; j < results.size() - 1; j++) {
                double engine_size1 = stod(results[j][6]); // Remove "std::"
                double engine_size2 = stod(results[j + 1][6]); // Remove "std::"
                if (engine_size1 > engine_size2) {
                    swap(results[j], results[j + 1]); // Remove "std::"
                }
            }
        }

        // Display the sorted results
        for (int i = 0; i < results.size(); i++)
        {
            for (int j = 0; j < results[i].size(); j++)
            {
                cout << results[i][j] << ",";
            }
            cout << "\n";
        }
    }


    struct Invoice {
        string invoice_id;
        string vehicle_title;
        string registration_year;
        string mileage;
        string engine_size;
        string url;
        string invoice_date;
        float price;
    };

    vector<Invoice> invoices;

    void create_invoice(const vector<vector<string>>& content) {
        static int id_counter = 1;
        string invoice_id = "ID" + to_string(id_counter++);
        float price = 0.0;
        string invoice_date, url;
        string registration_year;
        string mileage, engine_size;


        // Get vehicle title from user input
        string vehicle_title;
        cout << "Enter the complete vehicle title:  ";
        getline(cin, vehicle_title);

        bool found = false;
        while (!found) {
            for (const auto& row : content) {
                if (row[0] == vehicle_title) {
                    price = stof(row[1].substr(2));
                    registration_year = row[2];
                    mileage = row[3];
                    engine_size = row[6];
                    url = row[10];
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            cout << "Vehicle not found. Please enter a valid title." << endl;
            cout << "Enter the complete vehicle title:  ";
            getline(cin, vehicle_title);
        }

        // Get invoice date from user input
        cout << "Enter the invoice date (YYYY-MM-DD): ";
        getline(cin, invoice_date);

        // Create invoice 
        struct Invoice invoice = {
            invoice_id,
            vehicle_title,
            registration_year,
            mileage,
            engine_size,
            url,
            invoice_date,
            price
        };

        // Add invoice to vector
        invoices.push_back(invoice);

        // Print invoice details
        cout << "\nInvoice ID: " << invoice_id << endl;
        cout << "Vehicle Title: " << vehicle_title << endl;
        cout << "___________________________ " << endl;
        cout << "Vehicle Description " << endl;
        cout << "___________________________ " << endl;
        cout << "Registration Year: " << registration_year << endl;
        cout << "Mileage: " << mileage << endl;
        cout << "Engine Size: " << engine_size << endl;
        cout << "URL: " << url << endl;
        cout << "Invoice Date: " << invoice_date << endl;
        cout << "Price: " << fixed << setprecision(2) << price << endl;

    }

};