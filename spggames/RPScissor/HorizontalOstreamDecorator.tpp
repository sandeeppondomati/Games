#include <sstream>
#include "HorizontalOstreamDecorator.hpp" 
using spgames::HorizontalOstreamDecorator; 
template<char c,int w>
HorizontalOstreamDecorator<c,w>::HorizontalOstreamDecorator(spgames::OstreamDecorator *rawPtr, std::string str):spgames::OstreamDecorator(rawPtr,str) 
{
}
template<char c,int w>
void HorizontalOstreamDecorator<c,w>::decorate(std::ostream &out)
{
    out<<std::left<<std::setfill(' ')<< std::setw(w-1) <<" ";
    out<<std::internal<<std::setfill(c)<<std::setw(w-1)<<c<<str;
    out<<std::right<<std::setfill(' ')<< std::setw(0)<<'\n';

    //follow the order of initiation
    if(nxt!=nullptr)
        nxt->decorate(out);
}
