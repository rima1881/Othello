#include "./BoardModifier.hpp"

BoardModifier::BoardModifier(Board* b){
    this -> board = b;
}


bool BoardModifier::check_d0(int i,int j,bool isBlack){

    if(i == 7)
        return false;

    i++;
    if( (*board)[i][j] -> getContent() == nullptr || (*board)[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    i++;

    while(i < 8){

        if( (*board)[i][j] -> getContent() == nullptr ) 
            break;
        
        if( (*board)[i][j] -> getContent() -> IsBlack() == isBlack )
            return true;

        i++;
    }

    return false;


}

bool BoardModifier::check_d45(int i,int j,bool isBlack){

    if(i == 7 || j == 7)
        return false;

    i++;
    j++;
    if( (*board)[i][j] -> getContent() == nullptr || (*board)[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    i++;
    j++;

    while(i < 8 && j < 8){

        if( (*board)[i][j] -> getContent() == nullptr )
            break;
        
        if( (*board)[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        i++;
        j++;
    }

    return false;


}

bool BoardModifier::check_d90(int i,int j,bool isBlack){
    
    if(j == 7)
        return false;

    j++;
    if( (*board)[i][j] -> getContent() == nullptr || (*board)[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    j++;

    while(j < 8){

        if( (*board)[i][j] -> getContent() == nullptr )
            break;
        
        if( (*board)[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        j++;
    }

    return false;

}

bool BoardModifier::check_d135(int i,int j,bool isBlack){

    if(i == 0 || j == 7)
        return false;

    i--;
    j++;
    if( (*board)[i][j] -> getContent() == nullptr || (*board)[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    i--;
    j++;

    while(j < 8 && i > -1){

        if( (*board)[i][j] -> getContent() == nullptr )
            break;
        
        if( (*board)[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        i--;
        j++;
    }

    return false;

}

bool BoardModifier::check_d180(int i,int j,bool isBlack){
    if(i == 0)
        return false;

    i--;
    if( (*board)[i][j] -> getContent() == nullptr || (*board)[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    i--;

    while(i > -1){

        if( (*board)[i][j] -> getContent() == nullptr )
            break;
        
        if( (*board)[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        i--;
    }

    return false;
}

bool BoardModifier::check_d225(int i,int j,bool isBlack){
    if( i==0 || j==0)
        return false;

    i--;
    j--;

    if( (*board)[i][j] -> getContent() == nullptr || (*board)[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    i--;
    j--;

    while(i > -1 && j > -1){

        if( (*board)[i][j] -> getContent() == nullptr )
            break;
        
        if( (*board)[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        i--;
        j--;
    }

    return false;
}

bool BoardModifier::check_d270(int i,int j,bool isBlack){

    if(j ==0)
        return false;

    j--;
    if( (*board)[i][j] -> getContent() == nullptr || (*board)[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    j--;

    while(j > -1){

        if( (*board)[i][j] -> getContent() == nullptr )
            break;
        
        if( (*board)[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        j--;
    }

    return false;

}

bool BoardModifier::check_d315(int i,int j,bool isBlack){

    if(i == 7 || j==0)
        return false;

    i++;
    j--;

    if( (*board)[i][j] -> getContent() == nullptr || (*board)[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    i++;
    j--;

    while(i < 8 && j > -1){

        if( (*board)[i][j] -> getContent() == nullptr )
            break;
        
        if( (*board)[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        i++;
        j--;
    }

    return false;
}
