#include "TypeOstreamDecorator.hpp" 
using spgames::TypeOstreamDecorator; 

template<std::ios_base::fmtflags type,char c,int w>
TypeOstreamDecorator<type, c, w>::TypeOstreamDecorator(OstreamDecorator *rawPtr, std::string str):OstreamDecorator(rawPtr,str) {};

template<std::ios_base::fmtflags type,char c,int w>
void TypeOstreamDecorator<type, c, w>::decorate(std::ostream &out)
{
        out.setf(type);
        out<<std::setfill(c)<<std::setw(w-1)<<str;
        //follow the order of initiation
        if(nxt!=nullptr)
            nxt->decorate(out);
}
