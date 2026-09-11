#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
class Reservation { int id; std::string student,resourceId,date; public: Reservation(int,const std::string&,const std::string&,const std::string&); int getId()const; std::string getStudent()const; std::string getResourceId()const; std::string getDate()const; void display()const; };
#endif
