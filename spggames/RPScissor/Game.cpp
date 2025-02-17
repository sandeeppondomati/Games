#include"Game.hpp"
#include"GameImpl.hpp"

using spgames::Game;

Game::Game(std::unique_ptr<spgames::GameImpl> &&implTPtr):implPtr(std::move(implTPtr))
{
    implTPtr=nullptr;
}
Game::~Game(){}
