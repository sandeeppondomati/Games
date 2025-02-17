#include <cstdlib>  
#include <iostream>
#include <string>
#include <memory>
#include "RPSGameBuilder.hpp" 
#include "Game.hpp" 
#include "SingletonGenerator.hpp" 
#include "RandomGenerator.hpp" 
int main()
{
    using namespace spgames;
    
    RPSGameBuilder builder;
    builder.addPlayer("You");
    std::shared_ptr<Game> myGame = builder.createGame();
    myGame->start();
    myGame->stop();
    return 0;
}
