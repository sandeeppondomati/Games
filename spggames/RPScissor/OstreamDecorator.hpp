#ifndef __OSTREAMDECORATOR__HPP__
#define __OSTREAMDECORATOR__HPP__

#include<string>
#include<iomanip>
namespace spgames {

class OstreamDecorator
{
    public:
    OstreamDecorator(OstreamDecorator *rawPtr, std::string& str):nxt(rawPtr),str(str) {};
    virtual void decorate(std::ostream &out) = 0;
    virtual ~OstreamDecorator() {}

    protected:
    std::shared_ptr<OstreamDecorator> nxt;
    std::string str;
};

}
#endif
