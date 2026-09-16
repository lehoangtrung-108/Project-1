#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation {
public:
    // Default constructor:
    // Creates an empty Reservation object with all fields initialized to
    // empty strings. This allows the program to create a reservation object
    // before real reservation data is provided.
    Reservation();

    // Full constructor:
    // Creates one complete reservation using the information stored in
    // reservations.txt: reservation ID, student ID, student name, resource ID,
    // and reservation date. The values are passed by const reference to avoid
    // unnecessary string copies when creating the reservation.
    Reservation(const std::string &reservationId,
                const std::string &studentId,
                const std::string &studentName,
                const std::string &resourceId,
                const std::string &date);

    // Getter methods:
    // Return individual pieces of reservation information so other classes,
    // such as LinkedList and ReservationManager, can search and manage
    // reservations without directly accessing the private member variables.
    std::string getReservationId() const;
    std::string getStudentId() const;
    std::string getStudentName() const;
    std::string getResourceId() const;
    std::string getDate() const;

    // Display method:
    // Prints all information for this reservation in a readable format.
    // Used when displaying the active reservations stored in the linked list.
    void print() const;

private:
    // Unique identifier for this reservation.
    // Used by ReservationManager to distinguish one reservation from another
    // and to prevent duplicate reservation IDs.
    std::string reservationId_;

    // Identifier of the student who made the reservation.
    // Used when finding or displaying reservations belonging to a student.
    std::string studentId_;

    // Full name of the student who made the reservation.
    // Stored for displaying reservation information to the user.
    std::string studentName_;

    // Identifier of the resource being reserved.
    // This ID connects the reservation to a resource in the resource inventory.
    std::string resourceId_;

    // Date associated with the reservation.
    // Stored as a string because the project reservation data uses a text
    // date format loaded from the input file.
    std::string date_;
};

#endif