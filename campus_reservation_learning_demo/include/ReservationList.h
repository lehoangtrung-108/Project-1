#ifndef RESERVATION_LIST_H
#define RESERVATION_LIST_H
#include "Reservation.h"
class ReservationList { struct Node { Reservation data; Node* next; Node(const Reservation& r):data(r),next(nullptr){} }; Node* head; public: ReservationList(); ~ReservationList(); bool insert(const Reservation&); bool remove(int,Reservation&); bool contains(int)const; void display()const; };
#endif
