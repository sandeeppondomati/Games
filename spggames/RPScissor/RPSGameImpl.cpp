#include<iostream>
#include<climits>
#include<cctype>
#include<sstream>
//#include<format>
#include<string_view>
#include"RPSGameImpl.hpp"
#include"Player.hpp"
#include"RandomGenerator.hpp"
#include"SingletonGenerator.hpp"
#include  "HorizontalOstreamDecorator.tpp"
#include  "VerticalOstreamDecorator.tpp"
#include  "TypeOstreamDecorator.tpp"

using spgames::RPSGameImpl;


const std::unordered_map<char,std::string> RPSGameImpl::choiceMap={{'R',"Rock"},{'S',"Scissors"},{'P',"Paper"}};
const std::unordered_map<RPSGameImpl::ResultsEnum,std::string> RPSGameImpl::resultMap={{RPSGameImpl::ResultsEnum::Player,"You won!!!"},{RPSGameImpl::ResultsEnum::Computer,"Computer won!!!"},{RPSGameImpl::ResultsEnum::Tie,"Its a tie!!!"},{RPSGameImpl::ResultsEnum::None,"None"}};


RPSGameImpl::~RPSGameImpl() {}


bool RPSGameImpl::addPlayer(std::unique_ptr<Player> && otherPlayer) noexcept
{
    this->otherPlayer=std::move(otherPlayer);
    otherPlayer=nullptr;
   
    return true;
}

std::string RPSGameImpl::scores() const noexcept 
{
     // Clean up on decorator to remove manual formating
     std::stringstream ss;
     ss<<otherPlayer->getScore(); ss<<"                    "; ss<<defaultComputerPlayer->getScore();
     return ss.str();
}

void RPSGameImpl::start() noexcept
{
    bool toRun=true, toDisplayScores=false;
    do
    {
        int n=0;

        displayBanner(toDisplayScores);

        while(!(std::cin >> n) )
        {
            std::cin.clear();
            std::string line;
            std::getline(std::cin, line);
            displayBanner();
        }

        switch(n)
        {
            case 1:
            {
                toDisplayScores=false;

                defaultComputerPlayer->resetScore();
                otherPlayer->resetScore();

                std::string choices("None             None"), results("None");
                displayPlayBanner(choices, resultMap.at(ResultsEnum::None));

                play();
                break; 
             }
             case 2:
             {
                toDisplayScores=true;
                break; 
             }
             case 3:
             {
                system("clear");
                toRun=false; 
                break; 
             }
             default:
             {
                 break;
             }
         }
    }while(toRun);
}
    
void RPSGameImpl::stop() noexcept
{
    exit(0);
}
    
void RPSGameImpl::help() noexcept  
{
}

void RPSGameImpl::displayBanner(bool toDisplayScores) noexcept
{
    system("clear");
    HorizontalOstreamDecorator<'\n',30> temp(nullptr, "");
    temp.decorate(std::cout);
    if(toDisplayScores)
    {
        HorizontalOstreamDecorator<'*',80> score(
                                                new VerticalOstreamDecorator<'*',80,'\n'>(
                                                new HorizontalOstreamDecorator<'*',80>(
                                                nullptr,
                                                                        ""),
                                                                        "You          |          Computer"),
                                                                        "");
        score.decorate(std::cout);
        scoresV->decorate(std::cout);
        VerticalOstreamDecorator<'*',80,'\n'> scoresV1(new VerticalOstreamDecorator<'*',80,'\n'>(nullptr,"             |          "), scores());
        scoresV1.decorate(std::cout);
   }
   initialBanner->decorate(std::cout);
}

void RPSGameImpl::displayPlayBanner(const std::string &chs, const std::string& res) noexcept  
{
    system("clear");
    initialPlayBanner->decorate(std::cout);
    scoresV->decorate(std::cout);
    VerticalOstreamDecorator<'*',80,'\n'> scoresV1(nullptr, scores());
    scoresV1.decorate(std::cout);
    scoresV2->decorate(std::cout);

    choices->decorate(std::cout);
    VerticalOstreamDecorator<'*',80,'\n'> choices1(nullptr, chs);
    choices1.decorate(std::cout);
    scoresV2->decorate(std::cout);

    results->decorate(std::cout);
    VerticalOstreamDecorator<'*',80,'\n'> results1(nullptr, res); 
    results1.decorate(std::cout);
    results2->decorate(std::cout);

    startPlayBanner->decorate(std::cout);
}

void RPSGameImpl::play() noexcept
{
    bool toRun = true;
    do
    {
        char c=0;
        while(!(std::cin >> c) )
        {
            std::cin.clear();
            std::string line;
            std::getline(std::cin, line);
        }
        c=std::toupper(c);
        switch(c)
        {
            case 'R':
            case 'P':
            case 'S':
            {	
                // generate the random number to identify the computer choice
                // TODO: to make async call at the same time as cin - a trial and error 
                char randomChoice=choice[spgames::SingletonGenerator<RandomGenerator<1,3>>::getInstance()->generate()-1];

                // clean up to remove manual formatting
                std::stringstream choices; choices<<choiceMap.at(c); choices<<"                    "; choices<<choiceMap.at(randomChoice);
    		ResultsEnum results=ResultsEnum::None;

                switch(randomChoice)
                {
                    case 'P':
                    {
                        if(c == 'S')
 		        {
			    results=ResultsEnum::Player;
                            otherPlayer->addToScore(1);
  		        }
 		        else if(c == 'R')
   		        {
			    results=ResultsEnum::Computer;
                            defaultComputerPlayer->addToScore(1);
		        }
 		        else
		        {
			    results=ResultsEnum::Tie;
		        }
		        break;
   		    }
                    case 'S':
                    {   		:q!

                        if(c == 'R')
                        {   
			    results=ResultsEnum::Player;
                            otherPlayer->addToScore(1);
                        }
                        else if(c == 'P')
                        {   
			    results=ResultsEnum::Computer;
                            defaultComputerPlayer->addToScore(1);
                        }
                        else
                        {
			    results=ResultsEnum::Tie;
                        }
                        break;
                    }
                    case 'R':      
                    {
                        if(c == 'P')
                        {
			    results=ResultsEnum::Player;
                            otherPlayer->addToScore(1);
                        } 
                        else if(c == 'S')
                        {
			    results=ResultsEnum::Computer;
                            defaultComputerPlayer->addToScore(1);
                        }
                        else
                        {
			    results=ResultsEnum::Tie;
                        }
                        break;
                    }

                }
                displayPlayBanner(choices.str(), resultMap.at(results));
                break;
            }
            case 'E':
            {
                toRun=false;
                break;
            }
            default:
            {
                std::stringstream choices, results; choices<<("None                 None"); results<<"Invalid choice: "; results<<c; results<<" - Try again"; 
                displayPlayBanner(choices.str(), results.str());
            }
        }
    } while(toRun);
}

RPSGameImpl::RPSGameImpl():spgames::GameImpl()
{
    defaultComputerPlayer=std::make_unique<spgames::Player>((std::string_view("Computer")), INT_MAX);

    // decorators need to be cleaned
    initialBanner = std::make_unique<HorizontalOstreamDecorator<'*',80>>(
                                                new VerticalOstreamDecorator<'*',80,'\n'>(
                                                new HorizontalOstreamDecorator<'*',80>(
                                                new VerticalOstreamDecorator<'*',80,'\n'>(
                                                new HorizontalOstreamDecorator<'*',80>(
                                                new TypeOstreamDecorator<std::ios_base::left,' ',80>(
                                                new TypeOstreamDecorator<std::ios_base::left,' ',17>(
                                                nullptr,
                                                                        "Choose an option:"),
                                                                        ""),
                                                                        ""),
                                                                        std::string(START_BANNER)),
                                                                        ""),
                                                                        std::string(START_GAME_BANNER)),
                                                                        "");

    initialPlayBanner = std::make_unique<HorizontalOstreamDecorator<'\n',30>> (
                                                new HorizontalOstreamDecorator<'*',80>(
                                                new VerticalOstreamDecorator<'*',80,'\n'>(
                                                new HorizontalOstreamDecorator<'*',80>(
                                                new VerticalOstreamDecorator<'*',80,'\n'>(
                                                new HorizontalOstreamDecorator<'*',80>(
                                                nullptr,
                                                                        ""),
                                                                        "You          |          Computer"),
                                                                        ""),
                                                                        "Enjoy Rock-Paper-Scissor game!!!"),
                                                                        ""),
                                                                        "");
    scoresV =  std::make_unique<VerticalOstreamDecorator<'*',80,'\n'>>(
                                                new VerticalOstreamDecorator<'*',80,'\n'>(
                                                new TypeOstreamDecorator<std::ios_base::left,' ',73>(
                                                new TypeOstreamDecorator<std::ios_base::left,' ',6>(
                                                           nullptr,
                                                                                        "Scores:*                                 |                                           *\n"),
                                                                                        " "),
                                                                                        "             |          "),
                                                                                        "             |          ");
    scoresV2=std::make_unique<VerticalOstreamDecorator<'*',80,'\n'>>( new HorizontalOstreamDecorator<'*',80>(
                                                             nullptr,
                                                                                        ""),
                                                                                        "             |          ");
    choices=std::make_unique<VerticalOstreamDecorator<'*',80,'\n'>>(
                                                new VerticalOstreamDecorator<'*',80,'\n'>(
                                                new TypeOstreamDecorator<std::ios_base::left,' ',72>(
                                                new TypeOstreamDecorator<std::ios_base::left,' ',7>(
                                                           nullptr,
                                                                                        "Choices:*                                 |                                           *\n"),
                                                                                        " "),
                                                                                        "             |          "),
                                                                                        "             |          ");
    results=std::make_unique<VerticalOstreamDecorator<'*',80,'\n'>>(
                                                new VerticalOstreamDecorator<'*',80,'\n'>(
                                                new TypeOstreamDecorator<std::ios_base::left,' ',72>(
                                                new TypeOstreamDecorator<std::ios_base::left,' ',7>(
                                                           nullptr,
                                                                                        "Results:*                                                                             *\n"),
                                                                                        " "),
                                                                                        "                        "),
                                                                                        "                        ");
    results2=std::make_unique<VerticalOstreamDecorator<'*',80,'\n'>>( new HorizontalOstreamDecorator<'*',80>(
                                                             nullptr,
                                                                                        ""),
                                                                                        "                        ");
    startPlayBanner=std::make_unique<TypeOstreamDecorator<std::ios_base::left,' ',80>> (
								new TypeOstreamDecorator<std::ios_base::left,' ',START_PLAY_HELP.length()>(
								new TypeOstreamDecorator<std::ios_base::left,' ',80>(
								new TypeOstreamDecorator<std::ios_base::left,' ',START_PLAY.length()>(
											nullptr,std::string(START_PLAY)), " "), 
											std::string(START_PLAY_HELP)),
								" ");
    
}
