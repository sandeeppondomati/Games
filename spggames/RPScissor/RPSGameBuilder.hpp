#ifndef __RPS_GAME__BUILDER__HPP__
#define __RPS_GAME__BUILDER__HPP__

#include<memory>
#include<string_view>
#include"GameBuilder.hpp"
/*
// Base Template class
// Provides the basic API details to client
*/

namespace spgames {

class Game;
class RPSGameBuilderImpl;

class RPSGameBuilder : public GameBuilder
{
    public:

    RPSGameBuilder();
    virtual ~RPSGameBuilder();

    virtual std::shared_ptr<Game> createGame() noexcept override;

    virtual bool addPlayer(std::string_view && name) noexcept;
    

    protected:
    std::unique_ptr<RPSGameBuilderImpl> implPtr;

    private:

    // should not copy the Game
    RPSGameBuilder(const RPSGameBuilder &other) = delete;
    RPSGameBuilder(RPSGameBuilder &&other) = delete;
    RPSGameBuilder& operator = (const RPSGameBuilder &other) = delete;
    RPSGameBuilder& operator = (RPSGameBuilder &&other) = delete;
};

}
#endif
