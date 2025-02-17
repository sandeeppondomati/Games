#ifndef __TYPE_OSTREAMDECORATOR__HPP__
#define __TYPE_OSTREAMDECORATOR__HPP__
#include <sstream>
#include "OstreamDecorator.hpp" 
namespace spgames {
template<std::ios_base::fmtflags type,char c,int w>
class TypeOstreamDecorator : public OstreamDecorator
{
    public:
    TypeOstreamDecorator(OstreamDecorator *rawPtr, std::string str);
    void decorate(std::ostream &out) override;
};

}
#endif
