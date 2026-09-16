#include "CancellationHistory.h"
#include <iostream>

// Constructor
CancellationHistory::CancellationHistory()
    : topNode(nullptr), count(0)
{
    // Initialize topNode to nullptr so stack starts empty
}

// Destructor
CancellationHistory::~CancellationHistory()
{
    CancellationNode* current = topNode;
    while (current != nullptr)
    {
        CancellationNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    topNode = nullptr;
}

// push
void CancellationHistory::push(const Reservation &reservation)
{
    // Create new node pointing to current topNode
    CancellationNode* newNode = new CancellationNode(reservation, topNode);

    // Update topNode to point to new node
    topNode = newNode;

    // Increment stack size
    count++;
}

// pop
bool CancellationHistory::pop()
{
    // Check whether stack is empty
    if (isEmpty())
    {
        return false;
    }

    // 1. Remember current top node
    CancellationNode* temp = topNode;

    // 2. Move top pointer to next node down
    topNode = topNode->next;

    // 3. Delete old top node
    delete temp;

    // 4. Update size
    count--;
    return true;
}

// top
Reservation* CancellationHistory::top()
{
    if (isEmpty())
    {
        return nullptr;
    }

    return &(topNode->data);
}

// isEmpty
bool CancellationHistory::isEmpty() const
{
    return topNode == nullptr;
}

// display
void CancellationHistory::display() const
{
    if (isEmpty())
    {
        std::cout << "Cancellation history is empty." << std::endl;
        return;
    }

    CancellationNode* current = topNode;
    while (current != nullptr)
    {
        current->data.print();
        current = current->next;
    }
}

// size
int CancellationHistory::size() const
{
    return count;
}