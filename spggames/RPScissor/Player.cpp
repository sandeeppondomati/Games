#include"Player.hpp"

using spgames::Player;

const std::string_view& Player::getName() const noexcept
{
    return name;
}

const int Player::getId() const 
{
    return id;
}

const int Player::getScore() const
{
    return score;
}
    
void Player::resetScore() noexcept
{
    score=0;
}

void Player::addToScore(int score) noexcept
{
    this->score+=score;
}
