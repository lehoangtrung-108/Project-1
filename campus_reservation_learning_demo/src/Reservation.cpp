#include "Reservation.h"
#include <iostream>
Reservation::Reservation(int i,const std::string&s,const std::string&r,const std::string&d):id(i),student(s),resourceId(r),date(d){} int Reservation::getId()const{return id;} std::string Reservation::getStudent()const{return student;} std::string Reservation::getResourceId()const{return resourceId;} std::string Reservation::getDate()const{return date;} void Reservation::display()const{std::cout<<"#"<<id<<" | Student: "<<student<<" | Resource: "<<resourceId<<" | Date: "<<date<<'\n';}
