#include"GameBuilderImpl.hpp"
#include"RPSGameBuilderImpl.hpp"
#include"RPSGame.hpp"
#include"Player.hpp"

using spgames::RPSGameBuilderImpl;

RPSGameBuilderImpl::RPSGameBuilderImpl()
{
}

RPSGameBuilderImpl::~RPSGameBuilderImpl()
{
}


std::shared_ptr<spgames::Game> RPSGameBuilderImpl::createGame() noexcept
{
    std::shared_ptr<spgames::RPSGame> game = std::make_shared<RPSGame>();
    game->addPlayer(std::move(player));

    return game;
}
    
bool RPSGameBuilderImpl::addPlayer(std::string_view && name) noexcept
{
    player=std::make_unique<spgames::Player>(std::move(name), 1);
    return true;
}
