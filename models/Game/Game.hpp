#ifndef GAME_H
#define GAME_H
#include "../Player/Player.hpp"
#include "../Board/Board.hpp"
#include <vector>


class Game
{
private:

    bool color;
    int endGame;

    
    Player* Player1;
    Player* Player2;
    Board* board;

    //Managing functions
    void newGame(std::string name1,std::string name2);


    //onGame funcs
    void render();
    void showScores();

public:


    Game();

    void Menu();
    void Run();
    void FinalMSG();



};

#endif