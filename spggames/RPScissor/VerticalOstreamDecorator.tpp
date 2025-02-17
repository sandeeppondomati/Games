#include <sstream>
#include <algorithm>
#include "VerticalOstreamDecorator.hpp" 
using spgames::VerticalOstreamDecorator;
template<char c,int w,char d>
VerticalOstreamDecorator<c,w,d>::VerticalOstreamDecorator(OstreamDecorator *rawPtr, std::string str):OstreamDecorator(rawPtr,str) 
{
}
template<char c,int w,char d>
void VerticalOstreamDecorator<c,w,d>::decorate(std::ostream &out)
{
    std::istringstream ss(str);
    std::string breakString;
    while(std::getline(ss, breakString, d)) {
        int pad = (w-1-breakString.length())/2;
        out<<std::left<<std::setfill(' ')<< std::setw(std::max(0,w-1))<<" ";
        out<<c<<"                    "<<std::setfill(' ')<<std::setw(std::max(0, w-pad))<<std::left<<breakString;
        //out<<c<<std::setfill(' ')<<std::setw(std::max(0, w-pad))<<std::left<<breakString;
 	out<<std::right<<std::setfill(' ')<< std::setw(std::max(0,pad - 22))<<c<<d;
 	//out<<std::right<<std::setfill(' ')<< std::setw(std::max(0,pad - 2))<<c<<d;
     }

     //follow the order of initiation
     if(nxt!=nullptr)
         nxt->decorate(out);
}
