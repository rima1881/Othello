#include <iostream>
#include "./models/Game/Game.hpp"
#include "./models/Error/Error.hpp"

int main(){

    try{
        Game::LoadData("db/General.txt");
    }
    catch(Error err){
        std::cout << err.getMsg();
    }

    Game::Start();
    Game::Run();
    Game::FinalMSG();

    return 0;
}
