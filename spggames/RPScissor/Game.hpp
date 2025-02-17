#ifndef __GAME__HPP__
#define __GAME__HPP__
#include<memory>
#include<utility>

namespace spgames {

class GameImpl;
class Player;
/*
// Abstract Template class
// Provides the basic API details to client
*/
class Game
{
    public:

    Game(std::unique_ptr<spgames::GameImpl> &&implTPtr);

    virtual ~Game(); 

    virtual void start() noexcept = 0;
    
    virtual void stop() noexcept = 0;
    
    virtual void help() noexcept = 0;

    virtual bool addPlayer(std::unique_ptr<Player> && player) noexcept = 0;

    protected:
    std::unique_ptr<GameImpl> implPtr;

    private:
    // should not copy the Game
    Game(const Game &other) = delete;
    Game(Game &&other) = delete;
    Game& operator = (const Game &other) = delete;
    Game& operator = (Game &&other) = delete;

};

}
#endif
