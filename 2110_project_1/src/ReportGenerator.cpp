#include "ReportGenerator.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

ReportGenerator::ReportGenerator() {
    // Empty constructor for now.
}

string ReportGenerator::toLower(const string &text) {
    string result = text;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char ch) {
        return static_cast<char>(tolower(ch));
    });
    return result;
}

void ReportGenerator::generateResourceAvailabilityReport(
    const vector<Resource> &resources
) const {
    int availableCount = 0;
    int unavailableCount = 0;

    cout << "\n=== Resource Availability Report ===" << endl;
    for (size_t i = 0; i < resources.size(); ++i) {
        if (resources[i].isAvailable()) {
            ++availableCount;
        } else {
            ++unavailableCount;
        }

        cout << resources[i].getId() << " - " << resources[i].getName()
             << " - " << resources[i].getType() << " - "
             << (resources[i].isAvailable() ? "Available" : "Unavailable")
             << endl;
    }

    cout << "Available resources: " << availableCount << endl;
    cout << "Unavailable resources: " << unavailableCount << endl;
}

void ReportGenerator::generateReservationSummaryReport(
    const vector<Reservation> &reservations
) const {
    cout << "\n=== Reservation Summary Report ===" << endl;
    cout << "Total active reservations: " << reservations.size() << endl;

    if (reservations.empty()) {
        cout << "No reservations currently recorded." << endl;
        return;
    }

    cout << "Recent reservations:" << endl;
    for (size_t i = 0; i < reservations.size(); ++i) {
        cout << reservations[i].getReservationId() << " | "
             << reservations[i].getStudentName() << " | "
             << reservations[i].getResourceId() << " | "
             << reservations[i].getDate() << endl;
    }
}

void ReportGenerator::printMostReservedResources(
    const vector<Reservation> &reservations,
    const vector<Resource> &resources
) const {
    map<string, int> resourceCounts;
    map<string, string> resourceNames;

    for (size_t i = 0; i < resources.size(); ++i) {
        resourceNames[resources[i].getId()] = resources[i].getName();
    }

    for (size_t i = 0; i < reservations.size(); ++i) {
        const string resourceId = reservations[i].getResourceId();
        resourceCounts[resourceId]++;
    }

    cout << "\n=== Most Frequently Reserved Resources ===" << endl;
    if (resourceCounts.empty()) {
        cout << "No reservations found." << endl;
        return;
    }

    vector<pair<string, int>> sortedResources(resourceCounts.begin(), resourceCounts.end());
    sort(sortedResources.begin(), sortedResources.end(),
         [](const pair<string, int> &a, const pair<string, int> &b) {
             return a.second > b.second;
         });

    for (size_t i = 0; i < sortedResources.size(); ++i) {
        const string &id = sortedResources[i].first;
        const int count = sortedResources[i].second;
        const string name = resourceNames.count(id) ? resourceNames[id] : "Unknown Resource";
        cout << (i + 1) << ". " << id << " - " << name
             << " | reservations: " << count << endl;
    }
}

void ReportGenerator::generateWaitingListReport(
    const vector<Reservation> &waitingRequests
) const {
    cout << "\n=== Waiting List Report ===" << endl;
    cout << "Number of waiting requests: " << waitingRequests.size() << endl;

    for (size_t i = 0; i < waitingRequests.size(); ++i) {
        cout << (i + 1) << ". " << waitingRequests[i].getStudentName()
             << " requested resource " << waitingRequests[i].getResourceId()
             << " on " << waitingRequests[i].getDate() << endl;
    }
}
