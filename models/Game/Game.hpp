#ifndef GAME_H
#define GAME_H
#include "../Player/Player.hpp"
#include "../Board/Board.hpp"


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

    static void render();

public:

    /*
        all general variables are declared as pointer since they don't
        start from beginng of game however they will be need for the 
        whole general duration of game. 
        on top of this them being static made my life much easier :)


        they will be initialised during load or start
    */
    static Player* Player1;
    static Player* Player2;
    static Board* board;

    //onGame funcs
    static void TakeTurn();
    static bool CheckMove();
    static bool EndingMove();


    //general funcs
    static void StartGame(int state,std::string name1 , std::string name2);
    static bool SaveGame();
    static bool Load();


    static void FinalMSG(bool winner);

};

#endif