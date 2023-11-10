#include "./Board.hpp"


std::array<bool,8> Board::check_Position(int i,int j,Color c){
    
    std::array<bool ,8> res;
    res[0] = check_d0(i,j,c);
    res[1] = check_d45(i,j,c);
    res[2] = check_d90(i,j,c);
    res[3] = check_d135(i,j,c);
    res[4] =  check_d180(i,j,c); 
    res[5] = check_d225(i,j,c);
    res[6] = check_d270(i,j,c);
    res[7] = check_d315(i,j,c);

    return res;

}

bool Board::check_d0(int i,int j,Color c){

    i++;
    if(map[i][j] -> isEmpty() || map[i][j] -> getContent() -> getColor() == c){
        return false;
    }



    i++;

    while (true)
    {

        if(map[i][j] -> isEmpty())
            return false;

        if(map[i][j] -> getContent() -> getColor() == c)
            return true;

        i++;
    }
    
    return false;

}

bool Board::check_d45(int i,int j,Color c){

    i++;
    j++;
    if(map[i][j] -> isEmpty() || map[i][j] -> getContent() -> getColor() == c)
        return false;

    i++;
    j++;

    while (true)
    {

        if(map[i][j] -> isEmpty())
            return false;

        if(map[i][j] -> getContent() -> getColor() == c)
            return true;

        i++;
        j++;
    }
    
    return false;


}

bool Board::check_d90(int i,int j,Color c){
    
    j++;
    if(map[i][j] -> isEmpty() || map[i][j] -> getContent() -> getColor() == c)
        return false;

    j++;

    while (true)
    {

        if(map[i][j] -> isEmpty())
            return false;

        if(map[i][j] -> getContent() -> getColor() == c)
            return true;

        j++;
    }
    
    return false;

}

bool Board::check_d135(int i,int j,Color c){

    i--;
    j++;
    if(map[i][j] -> isEmpty() || map[i][j] -> getContent() -> getColor() == c)
        return false;

    i--;
    j++;

    while (true)
    {

        if(map[i][j] -> isEmpty())
            return false;

        if(map[i][j] -> getContent() -> getColor() == c)
            return true;

        i--;
        j++;
    }
    
    return false;

}

bool Board::check_d180(int i,int j,Color c){
    
    i--;
    if(map[i][j] -> isEmpty() || map[i][j] -> getContent() -> getColor() == c)
        return false;

    i--;

    while (true)
    {

        if(map[i][j] -> isEmpty())
            return false;

        if(map[i][j] -> getContent() -> getColor() == c)
            return true;

        i--;
    }
    
    return false;

}

bool Board::check_d225(int i,int j,Color c){

    i--;
    j--;
    if(map[i][j] -> isEmpty() || map[i][j] -> getContent() -> getColor() == c)
        return false;

    i--;
    j--;

    while (true)
    {

        if(map[i][j] -> isEmpty())
            return false;

        if(map[i][j] -> getContent() -> getColor() == c)
            return true;

        i--;
        j--;
    }
    
    return false;
}

bool Board::check_d270(int i,int j,Color c){

    j--;
    if(map[i][j] -> isEmpty() || map[i][j] -> getContent() -> getColor() == c)
        return false;

    j--;

    while (true)
    {

        if(map[i][j] -> isEmpty())
            return false;

        if(map[i][j] -> getContent() -> getColor() == c)
            return true;

        j--;
    }
    
    return false;

}

bool Board::check_d315(int i,int j,Color c){

    i++;
    j--;
    if(map[i][j] -> isEmpty() || map[i][j] -> getContent() -> getColor() == c)
        return false;

    i++;
    j--;

    while (true)
    {

        if(map[i][j] -> isEmpty())
            return false;

        if(map[i][j] -> getContent() -> getColor() == c)
            return true;

        i++;
        j--;
    }
    
    return false;

}
