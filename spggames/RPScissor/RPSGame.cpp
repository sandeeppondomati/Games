#include<utility>
#include"GameImpl.hpp"
#include"RPSGame.hpp"
#include"RPSGameImpl.hpp"

using spgames::RPSGame;

RPSGame::RPSGame():Game(std::make_unique<RPSGameImpl>())
{
}

RPSGame::~RPSGame() {}

void RPSGame::start() noexcept
{
    implPtr->start();
}
    
void RPSGame::stop() noexcept
{
    implPtr->stop();
}
    
void RPSGame::help() noexcept
{
     implPtr->help();
}

bool RPSGame::addPlayer(std::unique_ptr<Player> && player) noexcept
{
    return implPtr->addPlayer(std::move(player));
}
