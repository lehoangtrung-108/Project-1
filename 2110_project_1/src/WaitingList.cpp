#include "WaitingList.h"
#include <iostream>

// Constructor
WaitingList::WaitingList()
    : head(nullptr), tail(nullptr), count(0)
{
    // The queue starts empty with head and tail set to nullptr
}

// Destructor
WaitingList::~WaitingList()
{
    WaitingNode* current = head;
    while (current != nullptr)
    {
        WaitingNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

// enqueue
void WaitingList::enqueue(const Reservation &reservation)
{
    // Create a new WaitingNode storing the reservation request
    WaitingNode* newNode = new WaitingNode(reservation);

    // If the queue is empty: new node becomes both front (head) and back (tail)
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Otherwise: attach after current tail and update tail
        tail->next = newNode;
        tail = newNode;
    }

    count++;
}

// dequeue
bool WaitingList::dequeue()
{
    // Check whether the queue is empty
    if (isEmpty())
    {
        return false;
    }

    // 1. Remember current front node
    WaitingNode* temp = head;

    // 2. Move front pointer to next node
    head = head->next;

    // 3. Delete old front node
    delete temp;

    // 4. If queue became empty, update tail to nullptr as well
    if (head == nullptr)
    {
        tail = nullptr;
    }

    // 5. Update size
    count--;
    return true;
}

// front
Reservation* WaitingList::front()
{
    if (isEmpty())
    {
        return nullptr;
    }

    return &(head->data);
}

// isEmpty
bool WaitingList::isEmpty() const
{
    return head == nullptr;
}

// display
void WaitingList::display() const
{
    if (isEmpty())
    {
        std::cout << "Waiting list is currently empty." << std::endl;
        return;
    }

    WaitingNode* current = head;
    while (current != nullptr)
    {
        current->data.print();
        current = current->next;
    }
}

// size
int WaitingList::size() const
{
    return count;
}