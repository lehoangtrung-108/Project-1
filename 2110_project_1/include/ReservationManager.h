#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include "Resource.h"
#include "Reservation.h"
#include "Student.h"
#include "LinkedList.h"
#include "WaitingList.h"
#include "CancellationHistory.h"

#include <string>
#include <vector>

class ReservationManager
{
public:
    // Constructor
    ReservationManager();

    // Resource Management
    void addResource(const Resource &resource);

    // Initial File Loader Helper
    void loadActiveReservation(const Reservation &reservation);

    // Create Reservation
    bool createReservation(const std::string &reservationId,
                           const std::string &studentId,
                           const std::string &studentName,
                           const std::string &resourceId,
                           const std::string &date);

    // Cancel Reservation
    bool cancelReservation(const std::string &reservationId);

    // Display Active Reservations
    void displayActiveReservations() const;

    // Search Reservation
    Reservation* searchReservation(const std::string &reservationId);

    // Undo Cancellation
    bool undoCancellation();

    // Display Waiting Lists
    void displayWaitingLists() const;

    // Process Waiting List
    void processWaitingList(const std::string &resourceId);

private:
    std::vector<Resource> resources_;
    LinkedList activeReservations_;
    WaitingList waitingList_;
    CancellationHistory cancellationHistory_;

    // Private helpers
    Resource* findResource(const std::string &resourceId);
    bool isReservationIdUnique(const std::string &reservationId);
};

#endif