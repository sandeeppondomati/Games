#ifndef __RPS__GAME__IMPL__HPP__
#define __RPS__GAME__IMPL__HPP__
#include"GameImpl.hpp"
#include<string_view>
#include<unordered_map>
#include<memory>
#include<iomanip>


namespace spgames {

/*
// Abstract Template class
// Provides the basic API details to client
*/
class Player;
template<char c,int w>
class HorizontalOstreamDecorator;

template<char c,int w,char d>
class VerticalOstreamDecorator;

template<std::ios_base::fmtflags type,char c,int w>
class TypeOstreamDecorator;

class RPSGameImpl : public GameImpl
{
  enum class ResultsEnum {
        None,
        Player,
        Computer,
	Tie 
    };

    //static ResultsEnum results;
    // string literal constepr constructors are available yet in gcc (std=c++2a)
    static constexpr std::string_view START_GAME_BANNER{"Rock-Paper-Scissor Game!!!\n"};
    static constexpr std::string_view START_BANNER{"Choose from Below options:\n1:New Game\n2:Scores\n3:Exit\n"};
    static constexpr std::string_view START_PLAY_HELP{"(R=Rock, P=Paper and S=Scissor, E=Main Window)\n"};
    static constexpr std::string_view START_PLAY{"Please enter your choice R or S or P or E - "};
    static constexpr std::string_view choice="RPS";
    static const std::unordered_map<char,std::string> choiceMap;
    static const std::unordered_map<ResultsEnum,std::string> resultMap;

    public:
    
    RPSGameImpl();
    virtual ~RPSGameImpl(); 

    virtual void start() noexcept override;
    
    virtual void stop() noexcept override;
    
    virtual void help() noexcept override;

    virtual bool addPlayer(std::unique_ptr<Player> && player) noexcept override;


    protected:

    virtual void play() noexcept;
    virtual std::string scores() const noexcept;
    void displayPlayBanner(const std::string &chs, const std::string &res) noexcept;
    void displayBanner(bool toDisplayScores=false) noexcept;

    private:
 

    // should not copy the Game
    RPSGameImpl(const GameImpl &other) = delete;
    RPSGameImpl(GameImpl &&other) = delete;
    RPSGameImpl& operator = (const GameImpl &other) = delete;
    RPSGameImpl& operator = (GameImpl &&other) = delete;

    std::unique_ptr<Player> otherPlayer;
    std::unique_ptr<Player> defaultComputerPlayer;

    std::unique_ptr<HorizontalOstreamDecorator<'\n',30>> initialPlayBanner;
    std::unique_ptr<HorizontalOstreamDecorator<'*',80>> initialBanner;
    std::unique_ptr<VerticalOstreamDecorator<'*',80,'\n'>> scoresV;
    std::unique_ptr<VerticalOstreamDecorator<'*',80,'\n'>> scoresV2;
    std::unique_ptr<VerticalOstreamDecorator<'*',80,'\n'>> choices;
    std::unique_ptr<VerticalOstreamDecorator<'*',80,'\n'>> results;
    std::unique_ptr<VerticalOstreamDecorator<'*',80,'\n'>> results2;
    std::unique_ptr<TypeOstreamDecorator<std::ios_base::left,' ',80>> startPlayBanner;

};

}
#endif
