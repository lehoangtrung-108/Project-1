#ifndef WAITING_LINE_H
#define WAITING_LINE_H
#include <queue>
#include <string>
struct WaitRequest { std::string student,resourceId; };
class WaitingLine { std::queue<WaitRequest> q; public: void add(const std::string&,const std::string&); bool pop(WaitRequest&); void display()const; bool empty()const; };
#endif
