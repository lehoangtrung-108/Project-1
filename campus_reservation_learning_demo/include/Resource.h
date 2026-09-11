#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
class Resource { std::string id,name; bool available; public: Resource(const std::string&,const std::string&,bool=true); std::string getId()const; std::string getName()const; bool isAvailable()const; void setAvailable(bool); void display()const; };
#endif
