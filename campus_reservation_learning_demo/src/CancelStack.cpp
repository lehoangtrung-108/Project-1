#include "CancelStack.h"
#include <iostream>
void CancelStack::push(const Reservation&r){s.push(r);} bool CancelStack::pop(Reservation&r){if(s.empty())return false;r=s.top();s.pop();return true;} void CancelStack::display()const{if(s.empty()){std::cout<<"Cancellation history is empty.\n";return;}auto c=s;while(!c.empty()){c.top().display();c.pop();}} bool CancelStack::empty()const{return s.empty();}
