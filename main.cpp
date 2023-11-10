#include <iostream>
#include "./models/Game/Game.hpp"
#include "./models/Error/Error.hpp"

int main(){

    Game game;

    try{
        game.LoadData("db/General.txt");
    }
    catch(Error err){
        std::cout << err.getMsg();
    }

    while (game.Menu())
    {
        if(game.Run())
            game.FinalMSG();
    }
    


    return 0;
}
