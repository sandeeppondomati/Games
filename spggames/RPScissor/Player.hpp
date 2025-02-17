#ifndef __PLAYER__HPP__
#define __PLAYER__HPP__
#include<string_view>

namespace spgames {
/*
// Base class
// Provides the basic API details to client
*/
class Player
{
    public:

    constexpr Player(std::string_view &&nameT, int &&idT):name(std::move(nameT)),id(std::move(idT))
    {
        nameT="";
        idT=0;
    }

    virtual ~Player(){};

    virtual const std::string_view&  getName() const noexcept; 

    virtual const int getId() const; 

    virtual const int getScore() const;
    
    virtual void resetScore() noexcept;

    virtual void addToScore(int score) noexcept;

    private:
    std::string_view name="Guest";
    int id=1;
    int score = 0;
};

}
#endif
