#include "WaitingLine.h"
#include <iostream>
void WaitingLine::add(const std::string&s,const std::string&r){q.push({s,r});} bool WaitingLine::pop(WaitRequest&r){if(q.empty())return false;r=q.front();q.pop();return true;} void WaitingLine::display()const{if(q.empty()){std::cout<<"Waiting list is empty.\n";return;}auto c=q;int n=1;while(!c.empty()){std::cout<<n++<<". "<<c.front().student<<" -> Resource "<<c.front().resourceId<<'\n';c.pop();}} bool WaitingLine::empty()const{return q.empty();}
