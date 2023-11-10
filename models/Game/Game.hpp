#ifndef GAME_H
#define GAME_H
#include "../Player/Player.hpp"
#include "../Board/Board.hpp"
#include <vector>


class Game
{
private:

    bool blackTurn;
    int endGame;

    std::string savedGamesFileAddress;
    int initialMapsNumber;
    
    Player* Player1;
    Player* Player2;
    Board* board;

    //Managing functions
    void newGame(int state,std::string name1,std::string name2);
    void loadMap(std::string address);
    bool saveGame();


    //onGame funcs
    void render();
    void showScores();

public:


    Game();

    //General functions
    void LoadData(std::string general);
    void Start();
    void Run();
    void FinalMSG();


    //Getters



};

#endif