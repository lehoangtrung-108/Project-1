#include "ReservationManager.h"
#include <iostream>

// Constructor
ReservationManager::ReservationManager()
{
}

// Add Resource helper
void ReservationManager::addResource(const Resource &resource)
{
    resources_.push_back(resource);
}

// Load Active Reservation directly from initial file load
void ReservationManager::loadActiveReservation(const Reservation &reservation)
{
    // Insert into the active LinkedList
    activeReservations_.insert(reservation);

    // Mark the corresponding resource as unavailable
    Resource* resource = findResource(reservation.getResourceId());
    if (resource != nullptr)
    {
        resource->setAvailable(false);
    }
}

// Private Helper: Find Resource using res.getId()
Resource* ReservationManager::findResource(const std::string &resourceId)
{
    for (auto &res : resources_)
    {
        if (res.getId() == resourceId)
        {
            return &res;
        }
    }
    return nullptr;
}

// Private Helper: Check ID Uniqueness
bool ReservationManager::isReservationIdUnique(const std::string &reservationId)
{
    return activeReservations_.find(reservationId) == nullptr;
}

// Create Reservation
bool ReservationManager::createReservation(
    const std::string &reservationId,
    const std::string &studentId,
    const std::string &studentName,
    const std::string &resourceId,
    const std::string &date)
{
    // STEP 1: Check whether the reservation ID already exists
    if (!isReservationIdUnique(reservationId))
    {
        std::cout << "Error: Reservation ID " << reservationId << " already exists." << std::endl;
        return false;
    }

    // STEP 2: Check whether the resource ID exists
    Resource* resource = findResource(resourceId);
    if (resource == nullptr)
    {
        std::cout << "Error: Resource ID " << resourceId << " not found." << std::endl;
        return false;
    }

    // STEP 4: Create a Reservation object
    Reservation newRes(reservationId, studentId, studentName, resourceId, date);

    // STEP 3 & 5: If resource is available
    if (resource->isAvailable())
    {
        activeReservations_.insert(newRes);
        resource->setAvailable(false);
        std::cout << "Reservation " << reservationId << " created successfully." << std::endl;
        return true;
    }
    else
    {
        // STEP 6: If resource is unavailable, add request to WaitingList
        waitingList_.enqueue(newRes);
        std::cout << "Resource unavailable. Request added to waiting list." << std::endl;
        return true;
    }
}

// Cancel Reservation
bool ReservationManager::cancelReservation(const std::string &reservationId)
{
    // STEP 1: Search for the reservation
    Reservation* res = activeReservations_.find(reservationId);

    // STEP 2: If it doesn't exist, report failure
    if (res == nullptr)
    {
        std::cout << "Error: Reservation ID " << reservationId << " not found." << std::endl;
        return false;
    }

    std::string resId = res->getResourceId();

    // STEP 3: Save the reservation in CancellationHistory
    cancellationHistory_.push(*res);

    // STEP 4: Remove it from the active reservation LinkedList
    activeReservations_.remove(reservationId);

    // STEP 5 & 6: Find its Resource and mark it available
    Resource* resource = findResource(resId);
    if (resource != nullptr)
    {
        resource->setAvailable(true);
    }

    std::cout << "Reservation " << reservationId << " cancelled." << std::endl;

    // STEP 7: Check whether anyone is waiting for this resource
    processWaitingList(resId);

    // STEP 8: Return success
    return true;
}

// Display Active Reservations
void ReservationManager::displayActiveReservations() const
{
    std::cout << "--- Active Reservations ---" << std::endl;
    activeReservations_.display();
}

// Search Reservation
Reservation* ReservationManager::searchReservation(const std::string &reservationId)
{
    return activeReservations_.find(reservationId);
}

// Undo Cancellation
bool ReservationManager::undoCancellation()
{
    // STEP 1: Check whether the cancellation history is empty
    if (cancellationHistory_.isEmpty())
    {
        std::cout << "No cancelled reservations to undo." << std::endl;
        return false;
    }

    // STEP 2: Get the most recent cancelled reservation
    Reservation* lastCancelled = cancellationHistory_.top();
    if (lastCancelled == nullptr)
    {
        return false;
    }

    Reservation resToRestore = *lastCancelled;

    // STEP 3: Restore that reservation to the active LinkedList
    activeReservations_.insert(resToRestore);

    // STEP 4 & 5: Find the corresponding Resource and update availability
    Resource* resource = findResource(resToRestore.getResourceId());
    if (resource != nullptr)
    {
        resource->setAvailable(false);
    }

    // STEP 6: Remove the reservation from the cancellation history
    cancellationHistory_.pop();

    std::cout << "Successfully restored reservation " << resToRestore.getReservationId() << std::endl;

    // STEP 7: Return success
    return true;
}

// Display Waiting Lists
void ReservationManager::displayWaitingLists() const
{
    std::cout << "--- Waiting List Requests ---" << std::endl;
    waitingList_.display();
}

// Process Waiting List
void ReservationManager::processWaitingList(const std::string &resourceId)
{
    // STEP 1: Find the requested Resource
    Resource* resource = findResource(resourceId);

    // STEP 2: Confirm that the Resource is available
    if (resource == nullptr || !resource->isAvailable())
    {
        return;
    }

    // STEP 3 & 4: Check whether anyone is waiting
    if (waitingList_.isEmpty())
    {
        return;
    }

    // STEP 5: Take the FIRST request from the queue
    Reservation* waitingReq = waitingList_.front();
    if (waitingReq != nullptr && waitingReq->getResourceId() == resourceId)
    {
        Reservation nextRes = *waitingReq;
        waitingList_.dequeue();

        // STEP 6: Create/activate the reservation
        activeReservations_.insert(nextRes);

        // STEP 7: Update Resource availability
        resource->setAvailable(false);

        std::cout << "Promoted waiting request " << nextRes.getReservationId() 
                  << " to active reservation." << std::endl;
    }
}