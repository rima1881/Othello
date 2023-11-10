#include "./Game.hpp"
#include<windows.h>
#include <iostream>
#include <fstream>
#include "../Piece/Piece.hpp"
#include "../UnPlayablePosition/UnPlayablePosition.hpp"

Game::Game(){

    blackTurn = false;
    endGame = 0;
    savedGamesFileAddress = "";
    initialMapsNumber = 1;

}


//This function loads the defaults of the program
/*

In order for program to work Fully this function
need a txt file located in DB folder. if the txt
file does not exist the game will continue with
minimal options.

if the txt file is some how removed the program
gives a link to user to download it manually

*/
void Game::LoadData(std::string general){

    std::ifstream reader(general);

    //get the firstline will in general txt is an address to a file for all saved games
    std::getline(reader,savedGamesFileAddress);

    //the next line will be the number of default maps
    /*
        the resone for this way of implymention was to give the user the power
        to customize it's initial maps and number of them
    */ 
   
    std::string line;
    std::getline(reader,line);
    initialMapsNumber = stoi(line);

}


void Game::newGame(int state,std::string name1,std::string name2){

    std::string mapAddress = "initialMaps/" + std::to_string(state) + ".txt";

    Player1 = new Player(name1, false);
    Player2 = new Player(name2, true);

    board = new Board();

    loadMap(mapAddress);

}






void Game::loadMap(std::string address){


    std::ifstream reader( "db/" +address);
    std::array<std::string,8> lines;

    for(int i=0;i<8;i++)
        std::getline(reader,lines[i]);


    Game::board = new Board(lines);
}



bool Game::saveGame(){

    std::string name;
    std::cout << "\nplease enter a name for save:";
    std::cin >> name;

    std::ofstream Save("db/Saves/" + name + ".txt");


    for(int i=1;i < 9;i++){
        for(int j=1;j < 9;j++){
            if((*board)[i][j] -> isEmpty())
                Save << ".";
            else if((*board)[i][j] -> getContent() -> getColor() == Color::White)
                Save << "W";
            else
                Save << "B";
        }
        Save << "\n";
    }

    Save << Player1 -> getName() << "\n" << Player2 -> getName();


    Save.close();

    std::ofstream Saves("db/" + savedGamesFileAddress);

    for(int i=0;i < saveLists.size();i++){
        Saves << saveLists[i] << "\n";
    }

    Saves << name;

    Saves.close();

    char res;
    std::cout << "Do you want to Continue the Game:(y/N)";
    std::cin >> res;    

    return res == 'y';
}

void Game::render(){

    system("cls");
    std::cout << "\n\n";
    Game::board -> Draw();

}

bool Game::Menu(){


    std::cout << "\n\n***********************************************\n";
    std::cout << "welcome to the Game:)\n";
    std::cout << "***********************************************\n\n";

    int option = 0;
    std::cout << std::endl;


    while(true) {
        std::cout << std::endl;


        std::cout << "1.New Game\n";
        std::cout << "2.Load\n";
        std::cout << "3.Exit\n\n";

        std::cout << "Please Choose from one of the options above :";


        std::cin >> option;

        if (option == 1){
            std::cout << std::endl;
            std::cout << "Please Enter Player1 name:";
            std::string name1 ,name2;
            std::cin >> name1;
            std::cout << "Please Enter Player2 name:";
            std::cin >> name2;
            int state;

            while (true)
            {
                std::cout << std::endl;
                std::cout << "Please Choose a number from 1 to " << this -> initialMapsNumber << " for initial Map:";
                std::cin >> state;

                if(state > 0 && state <= initialMapsNumber)
                    break;

                std::cout<< "Incorrect Number!!!";
            }


            newGame(state,name1,name2);


            break;
        }
        else if(option == 2){
            if(load())
                break;
            else
                continue;
        }
        else if(option == 3)
            return false;

        std::cout << "InCorrect Number!!!Please Choose between 1-3\n";

    }


    return true;
    

}

bool Game::loadSaves(){

    if(saveLists.size() == 0){
    std::ifstream reader( "db/" + savedGamesFileAddress);
    std::string line;

    while(std::getline(reader,line))
        saveLists.push_back(line);
    }

    if(saveLists.size() == 0)
        return false;

    return true;
}


bool Game::load(){

    if(!loadSaves()){
        std::cout << "\nThere is no saved file!!!";
        return false;
    }

    int choose;
    bool begone = false;

    while(!begone){

        std::cout << "\n" << "to Go back to menu enter -1" << "\n";
        std::cout << "please choose between Saves:" << "\n\n";

        for(int i=0;i < saveLists.size();i++){
            std::cout << i+1 << ") " <<saveLists[i] << std::endl;
        }

        std::cin.ignore();
        std::cin >> choose;

        if(choose == -1)
            return false;

        if(choose > 0 && choose <= saveLists.size())
            break;

        std::cout << "Incorrent Input!!!" << "\n";

    }

    loadGame(saveLists[choose-1]);

    return true;

}

void Game::loadGame(std::string address){

    address = "db/Saves/" + address + ".txt";
    std::ifstream reader(address);


    std::array<std::string,8> lines;

    for(int i=0;i<8;i++){
        std::getline(reader , lines[i]);
        std::cout << lines[i] << "\n";
    }

    std::string name1,name2;
    std::getline(reader,name1);
    std::getline(reader,name2);

    Player1 = new Player(name1, false);
    Player2 = new Player(name2, true);

    this -> board = new Board(lines);



}

bool Game::Run(){

    while(true){


        Color c = blackTurn ? Color::Black : Color::White;
        board -> Refresh(c);

        render();
        showScores();

        std::vector<Coordinate> AV = board -> getAvailableCoordinate();

        bool hasOption = AV.size() != 0;


        if(hasOption){

            Coordinate co = blackTurn ? Player2 -> takeTurn(AV) : Player1 -> takeTurn(AV);

            if(co.getI() == -50)
                if(saveGame())
                    return false;
            else if(co.getI() == -100){
                Player1 -> setScore(-100);
                return true;
            }
            
            board -> Put(co,c);

            endGame = 0;

        }else
            endGame++;

        if(endGame == 2)
            return true;
        
        blackTurn = !blackTurn;
    }
    

}


void Game::FinalMSG(){
    std::string winner = Player1 -> getScore() > Player2 -> getScore() ? Player1 -> getName() : Player2 -> getName();

    std::cout << winner << "has won :O\n";

    showScores();
}

void Game::showScores(){

    Player1 -> setScore( board -> Count (Color::White));
    Player2 -> setScore( board -> Count (Color::Black));

    std::cout << Player1 -> getName() << ": " << Player1 -> getScore();
    std::cout << std::endl;
    std::cout << Player2 -> getName() << ": " << Player2 -> getScore();
    std::cout << std::endl;


}