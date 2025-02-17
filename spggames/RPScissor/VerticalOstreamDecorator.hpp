#ifndef __VERTICAL_OSTREAMDECORATOR__HPP__
#define __VERTICAL_OSTREAMDECORATOR__HPP__
#include <sstream>
#include <algorithm>
#include "OstreamDecorator.hpp" 
namespace spgames {
template<char c,int w,char d>
class VerticalOstreamDecorator : public OstreamDecorator
{
    public:

    VerticalOstreamDecorator(OstreamDecorator *rawPtr, std::string str);
    void decorate(std::ostream &out) override;
};

}
#endif
