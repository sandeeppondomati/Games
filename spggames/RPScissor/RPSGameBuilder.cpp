#include<memory>
#include"GameBuilder.hpp"
#include"RPSGameBuilder.hpp"
#include"RPSGameBuilderImpl.hpp"

using spgames::RPSGameBuilder;

RPSGameBuilder::RPSGameBuilder():GameBuilder(),implPtr(std::make_unique<spgames::RPSGameBuilderImpl>())
{
}

RPSGameBuilder::~RPSGameBuilder() {}

std::shared_ptr<spgames::Game> RPSGameBuilder::createGame() noexcept
{
    return implPtr->createGame();
}
    

bool RPSGameBuilder::addPlayer(std::string_view && name) noexcept
{
    return implPtr->addPlayer(std::move(name));
}
