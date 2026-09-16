#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include "Resource.h"
#include "Reservation.h"

#include <string>
#include <vector>

class ReportGenerator {
public:
    ReportGenerator();

    // Displays how many resources are available and how many are unavailable.
    void generateResourceAvailabilityReport(
        const std::vector<Resource> &resources
    ) const;

    // Gives a quick summary of the current active reservations.
    void generateReservationSummaryReport(
        const std::vector<Reservation> &reservations
    ) const;

    // Shows which resources are reserved most often.
    void printMostReservedResources(
        const std::vector<Reservation> &reservations,
        const std::vector<Resource> &resources
    ) const;

    // Displays waiting requests in a simple queue-style report.
    void generateWaitingListReport(
        const std::vector<Reservation> &waitingRequests
    ) const;

private:
    // Helper used for clean string comparisons in report logic.
    static std::string toLower(const std::string &text);
};

#endif
