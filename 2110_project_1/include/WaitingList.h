// First-In, First-Out queue of waiting requests
#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include "Reservation.h"

// Node used to store one waiting-list request.
struct WaitingNode
{
    // Reservation data member
    Reservation data;

    // Pointer to the next WaitingNode
    WaitingNode* next;

    // Node constructor for quick initialization
    WaitingNode(const Reservation& res, WaitingNode* nextNode = nullptr)
        : data(res), next(nextNode) {}
};


class WaitingList
{
public:

    // Constructor: Initializes the waiting list so it starts empty.
    WaitingList();

    // Destructor: Deletes all dynamically allocated nodes to prevent memory leaks.
    ~WaitingList();

    // Enqueue: Adds a new waiting request to the BACK of the queue (FIFO).
    void enqueue(const Reservation &reservation);

    // Dequeue: Removes the request from the FRONT of the queue.
    // Returns true if a node was successfully removed, false if the queue was empty.
    bool dequeue();

    // Front: Looks at the first waiting request without removing it.
    // Returns a pointer to the front Reservation, or nullptr if empty.
    Reservation* front();

    // IsEmpty: Returns whether the waiting list contains no requests.
    bool isEmpty() const;

    // Display: Traverses the queue from FRONT to BACK and displays each request.
    void display() const;

    // Size: Returns the number of requests currently waiting.
    int size() const;

private:

    // Pointer to the first/front node in the queue.
    WaitingNode* head;

    // Pointer to the last/back node in the queue for O(1) enqueuing.
    WaitingNode* tail;

    // Variable to track the total number of waiting requests.
    int count;
};

#endif