#include "Resource.h"
#include <iostream>
Resource::Resource(const std::string&i,const std::string&n,bool a):id(i),name(n),available(a){} std::string Resource::getId()const{return id;} std::string Resource::getName()const{return name;} bool Resource::isAvailable()const{return available;} void Resource::setAvailable(bool v){available=v;} void Resource::display()const{std::cout<<id<<" | "<<name<<" | "<<(available?"Available":"Reserved")<<'\n';}
