#ifndef GAME_H
#define GAME_H
#include "../Player/Player.hpp"
#include "../BoardModifier/BoardModifier.hpp"
#include "../Board/Board.hpp"
#include <vector>


/*
    the design for game is a static class that controls the flow of
    the program. all management methods are migrated from board to 
    game because it made more sense to me. (letting board just be a
    board)

    pros of this design:
        no instance of game is created and methods of game can be used
        for callback

    cons:
        1.only one game can be played at time and to my logic it is not a
        problem because it dosn't make sence to me to play multiple games
        at the same time.

        2.

*/


class Game
{
private:

    static bool blackTurn;

        //I don't like them being static but I didn't want to think :)
    static std::vector<std::string> savedGames;
    static std::vector<std::string> initialMaps;

    static BoardModifier* BM;
    
    static Player* Player1;
    static Player* Player2;
    static Board* board;

    //Managing functions
    static void initialization();
    static void modifyBoard();
    static bool loadMap(std::string address);
    static bool saveGame();



    //onGame funcs
    static void render();
    static void takeTurn();
    static bool endingMove();

public:

    /*
        all general variables are declared as pointer since they don't
        start from beginng of game however they will be need for the 
        whole general duration of game. 
        on top of this them being static made my life much easier :)


        they will be initialised during load or start
    */

    //General functions
    static void LoadData(std::string general);
    static void Start();
    static void Run();
    static void FinalMSG();


    //Getters
    static std::vector<std::string> getSavedGames();
    static int getInitialMapsSize();



};

#endif