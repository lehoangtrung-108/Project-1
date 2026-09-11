#ifndef DEMO_MANAGER_H
#define DEMO_MANAGER_H
#include <vector>
#include <string>
#include "Resource.h"
#include "ReservationList.h"
#include "WaitingLine.h"
#include "CancelStack.h"
class DemoManager { std::vector<Resource> resources; ReservationList reservations; WaitingLine waiting; CancelStack cancelled; int nextId; Resource* findResource(const std::string&); public: DemoManager(); bool loadResources(const std::string&); void showResources()const; void createReservation(); void cancelReservation(); void showReservations()const; void showWaiting()const; void undo(); };
#endif
