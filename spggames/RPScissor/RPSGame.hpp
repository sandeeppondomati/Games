#ifndef __RPS__GAME__HPP__
#define __RPS__GAME__HPP__

#include "Game.hpp"

namespace spgames {

/*
// Concrete RPSGame class
// Provides the basic API details to client
*/
class RPSGame : public Game
{
    public:
    
    RPSGame();

    ~RPSGame();

    virtual void start() noexcept override;
    
    virtual void stop() noexcept override;
    
    virtual void help() noexcept override; 

    virtual bool addPlayer(std::unique_ptr<Player> && player) noexcept override;


    private:

    // should not copy the RPSGame
    RPSGame(const RPSGame &other) = delete;
    RPSGame(RPSGame &&other) = delete;
    RPSGame& operator = (const RPSGame &other) = delete;
    RPSGame& operator = (RPSGame &&other) = delete;

};

}
#endif
