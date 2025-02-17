#ifndef __GAME__IMPL__HPP__
#define __GAME__IMPL__HPP__

#include<memory>

namespace spgames {

class Player;
/*
// Abstract Template class
// Provides the basic API details to client
*/
class GameImpl
{
    public:

    constexpr GameImpl(){}

    virtual ~GameImpl() {}

    virtual void start() noexcept = 0;
    
    virtual void stop() noexcept = 0;
    
    virtual void help() noexcept = 0;

    virtual bool addPlayer(std::unique_ptr<Player> && player) noexcept = 0;

    private:

    // should not copy the Game
    GameImpl(const GameImpl &other) = delete;
    GameImpl(GameImpl &&other) = delete;
    GameImpl& operator = (const GameImpl &other) = delete;
    GameImpl& operator = (GameImpl &&other) = delete;
};

}
#endif
