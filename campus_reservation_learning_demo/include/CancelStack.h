#ifndef CANCEL_STACK_H
#define CANCEL_STACK_H
#include <stack>
#include "Reservation.h"
class CancelStack { std::stack<Reservation> s; public: void push(const Reservation&); bool pop(Reservation&); void display()const; bool empty()const; };
#endif
