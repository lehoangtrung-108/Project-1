#include "LinkedList.h"
#include <iostream>

// Constructor
LinkedList::LinkedList()
    : head(nullptr), count(0)
{
    // Initialize head to nullptr so list starts empty
}

// Destructor
LinkedList::~LinkedList()
{
    ReservationNode* current = head;
    while (current != nullptr)
    {
        ReservationNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

// Insert
void LinkedList::insert(const Reservation &reservation)
{
    ReservationNode* newNode = new ReservationNode(reservation, head);
    head = newNode;
    count++;
}

// Remove
bool LinkedList::remove(const std::string &reservationId)
{
    ReservationNode* current = head;
    ReservationNode* previous = nullptr;

    // Fixed method call: changed getId() to getReservationId()
    while (current != nullptr && current->data.getReservationId() != reservationId)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        return false;
    }

    if (previous == nullptr)
    {
        head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    delete current;
    count--;
    return true;
}

// Find
Reservation* LinkedList::find(const std::string &reservationId)
{
    ReservationNode* current = head;

    while (current != nullptr)
    {
        // Fixed method call: changed getId() to getReservationId()
        if (current->data.getReservationId() == reservationId)
        {
            return &(current->data);
        }
        current = current->next;
    }

    return nullptr;
}

// Display
void LinkedList::display() const
{
    if (head == nullptr)
    {
        std::cout << "No active reservations." << std::endl;
        return;
    }

    ReservationNode* current = head;
    while (current != nullptr)
    {
        current->data.print();
        current = current->next;
    }
}

// Size
int LinkedList::size() const
{
    return count;
}