#ifndef __GAME__BUILDER__HPP__
#define __GAME__BUILDER__HPP__

#include<memory>
/*
// Base Template class
// Provides the basic API details to client
*/

namespace spgames {

class Game;

class GameBuilder
{
    public:
   
    GameBuilder() {}
    
    virtual std::shared_ptr<Game> createGame() noexcept = 0;
    
    virtual ~GameBuilder() {}

    private:

    // should not copy the Game
    GameBuilder(const GameBuilder &other) = delete;
    GameBuilder(GameBuilder &&other) = delete;
    GameBuilder& operator = (const GameBuilder &other) = delete;
    GameBuilder& operator = (GameBuilder &&other) = delete;
};

}
#endif
