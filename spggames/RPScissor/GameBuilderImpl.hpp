#ifndef __GAME__BUILDER__IMPL__HPP__
#define __GAME__BUILDER__IMPL__HPP__

#include<memory>
#include<string_view>
/*
//Implementor class
// Provides the basic API details to client
*/

namespace spgames {


class Game;

class GameBuilderImpl
{
    public:
    
    GameBuilderImpl(); 
    virtual ~GameBuilderImpl(); 

    virtual std::shared_ptr<Game> createGame() noexcept = 0;

    private:
    // should not copy the Game
    GameBuilderImpl(const GameBuilderImpl &other) = delete;
    GameBuilderImpl(GameBuilderImpl &&other) = delete;
    GameBuilderImpl& operator = (const GameBuilderImpl &other) = delete;
    GameBuilderImpl& operator = (GameBuilderImpl &&other) = delete;
};

}
#endif
