#include "FileLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

vector<Resource> FileLoader::loadResources(const string &path) {
    ifstream in(path);

    if (!in){
        cerr << "Error: Could not open the file." << endl;
        return vector<Resource>();
    }

    vector<Resource> resources;
    string line;
    char delim = '|';

    while (getline(in, line)){
        if (line.empty()){
            continue;
        }

        // split each line on every '|' into each of the 4 expected fields.
        vector<string> fields;
        stringstream ss(line);
        string field;
        while (getline(ss, field, delim)){
            fields.push_back(field);
        }

        // a resource should only ever have 4 fields.
        if (fields.size() != 4){
            cerr << "Error: Incorrect resource data provided" << endl;
            continue;
        }

        // Last field in resources.txt determines whether a resource is available for reservation.
        bool avail = (fields[3] == "Available");

        // build the resource and add it to the results.
        resources.push_back(Resource(fields[0], fields[1], fields[2], avail));
    }
    return resources;
}

// FUNCTION loadReservations(path)
vector<Reservation> FileLoader::loadReservations(const string &path) {
    // 1. Open the file using the path
    ifstream in(path);

    // 2. Check whether the file opened successfully
    if (!in) {
        cerr << "Error: Could not open reservations file at " << path << endl;
        return vector<Reservation>();
    }

    // 3. Create an empty vector to store Reservation objects
    vector<Reservation> reservations;

    // 4. Create a variable for each line of the file
    string line;

    // 5. Set the delimiter to '|'
    char delim = '|';

    // 6. Read the file one line at a time
    while (getline(in, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }

        // 7. Create an empty vector of strings called fields
        vector<string> fields;

        // 8. Use a stringstream to split the line using '|'
        stringstream ss(line);
        string field;

        // 9. Put every separated field into fields
        while (getline(ss, field, delim)) {
            fields.push_back(field);
        }

        // 10. Check that there are exactly 5 fields
        if (fields.size() != 5) {
            cerr << "Error: Invalid reservation line format." << endl;
            continue;
        }

        // 11. Create a Reservation using fields[0] through fields[4]
        // 12. Add that Reservation to the vector
        reservations.push_back(Reservation(fields[0], fields[1], fields[2], fields[3], fields[4]));
    }

    // 13. Return the vector of Reservation objects
    return reservations;
}