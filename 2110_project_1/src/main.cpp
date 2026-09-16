#include <iostream>
#include <vector>
#include <string>
#include "FileLoader.h"
#include "ReservationManager.h"

using namespace std;

void displayMenu() {
    cout << "\n=========================================" << endl;
    cout << "     CAMPUS RESOURCE RESERVATION SYSTEM   " << endl;
    cout << "=========================================" << endl;
    cout << "1. Create Reservation" << endl;
    cout << "2. Cancel Reservation" << endl;
    cout << "3. Display Active Reservations" << endl;
    cout << "4. Display Waiting List Requests" << endl;
    cout << "5. Search Reservation by ID" << endl;
    cout << "6. Undo Last Cancellation" << endl;
    cout << "7. View All System Resources" << endl;
    cout << "8. Exit" << endl;
    cout << "=========================================" << endl;
    cout << "Enter your choice (1-8): ";
}

int main() {
    ReservationManager manager;

    // 1. Load resources from file and register with manager
    vector<Resource> resources = FileLoader::loadResources("data/resources.txt");
    for (size_t i = 0; i < resources.size(); ++i) {
        manager.addResource(resources[i]);
    }

    // 2. loadReservations() -> Reservation objects
    vector<Reservation> initialReservations = FileLoader::loadReservations("data/reservations.txt");
        
        cout << "Loaded reservations: " << initialReservations.size() << endl;

    // 3. Reservation objects -> ReservationManager -> activeReservations_.insert()
    for (size_t i = 0; i < initialReservations.size(); ++i) {
        manager.loadActiveReservation(initialReservations[i]);
    }

    int choice = 0;
    while (choice != 8) {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 8." << endl;
            continue;
        }

        switch (choice) {
            case 1: { // Create Reservation
                string resId, studentId, studentName, resourceId, date;
                cout << "\n--- Create Reservation ---" << endl;
                cout << "Enter Reservation ID: ";
                cin >> resId;
                cout << "Enter Student ID: ";
                cin >> studentId;
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, studentName);
                cout << "Enter Resource ID: ";
                cin >> resourceId;
                cout << "Enter Reservation Date (MM/DD/YYYY): ";
                cin >> date;

                manager.createReservation(resId, studentId, studentName, resourceId, date);
                break;
            }
            case 2: { // Cancel Reservation
                string resId;
                cout << "\n--- Cancel Reservation ---" << endl;
                cout << "Enter Reservation ID to cancel: ";
                cin >> resId;

                manager.cancelReservation(resId);
                break;
            }
            case 3: // Display Active Reservations
                manager.displayActiveReservations();
                break;

            case 4: // Display Waiting Lists
                manager.displayWaitingLists();
                break;

            case 5: { // Search Reservation
                string resId;
                cout << "\n--- Search Reservation ---" << endl;
                cout << "Enter Reservation ID: ";
                cin >> resId;

                Reservation* found = manager.searchReservation(resId);
                if (found != nullptr) {
                    cout << "Reservation Found:" << endl;
                    found->print();
                } else {
                    cout << "No active reservation found with ID " << resId << endl;
                }
                break;
            }
            case 6: // Undo Cancellation
                cout << "\n--- Undo Last Cancellation ---" << endl;
                manager.undoCancellation();
                break;

            case 7: // View All Loaded Resources
                cout << "\n--- System Resources ---" << endl;
                for (size_t i = 0; i < resources.size(); ++i) {
                    resources[i].print();
                }
                break;

            case 8: // Exit
                cout << "Exiting system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid selection. Please choose options 1 through 8." << endl;
                break;
        }
    }

    return 0;
}