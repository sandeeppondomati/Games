#ifndef __HORIZONTAL_OSTREAMDECORATOR__HPP__
#define __HORIZONTAL_OSTREAMDECORATOR__HPP__
#include <sstream>
#include "OstreamDecorator.hpp" 
namespace spgames {
template<char c,int w>
class HorizontalOstreamDecorator : public OstreamDecorator
{
    public:
    HorizontalOstreamDecorator(OstreamDecorator *rawPtr, std::string str);
    void decorate(std::ostream &out) override;
};

}
#endif
