#ifndef __RPS_GAME__BUILDER__IMPL__HPP__
#define __RPS_GAME__BUILDER__IMPL__HPP__

#include<memory>
#include<string_view>
#include"GameBuilderImpl.hpp"
/*
//Implementor class
// Provides the basic API details to client
*/

namespace spgames {


class Player;
class Game;

class RPSGameBuilderImpl : GameBuilderImpl
{
    public:
    
    RPSGameBuilderImpl();
    virtual ~RPSGameBuilderImpl();

    std::shared_ptr<Game> createGame() noexcept override;

    virtual bool addPlayer(std::string_view && name) noexcept;
    

    private:
    // should not copy the Game
    RPSGameBuilderImpl(const RPSGameBuilderImpl &other) = delete;
    RPSGameBuilderImpl(RPSGameBuilderImpl &&other) = delete;
    RPSGameBuilderImpl& operator = (const RPSGameBuilderImpl &other) = delete;
    RPSGameBuilderImpl& operator = (RPSGameBuilderImpl &&other) = delete;

    std::unique_ptr<Player> player;
};

}
#endif
