#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Reservation.h"
#include <string>

// Node used to store one Reservation in the linked list.
struct ReservationNode
{
    // Store one Reservation object in this node.
    Reservation data;

    // Pointer to the next node in the linked list.
    ReservationNode* next;

    // Constructor to initialize a node
    ReservationNode(const Reservation& res, ReservationNode* nextNode = nullptr)
        : data(res), next(nextNode) {}
};


class LinkedList
{
public:

    // Constructor: initialize the linked list so that it starts empty.
    LinkedList();

    // Destructor: release all dynamically allocated nodes.
    ~LinkedList();

    // Insert: receive a Reservation and add it to the linked list.
    void insert(const Reservation &reservation);

    // Remove: receive a reservation ID string and remove the matching reservation.
    bool remove(const std::string &reservationId);

    // Find: search the linked list for a reservation ID string.
    Reservation* find(const std::string &reservationId);

    // Display: traverse the entire linked list and display information for every active reservation.
    void display() const;

    // Size: return the number of reservations currently stored in the linked list.
    int size() const;

private:

    // Pointer to the first node in the linked list.
    ReservationNode* head;

    // Running count of the number of nodes in the list.
    int count;
};

#endif