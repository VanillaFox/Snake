#include <iostream>
#include "func.h"

int main(){
    srand(time(NULL));
    Setup();
    while(!GameOver){
        Map();
        Input();
        Logic();
    }
    std::cout << std::endl;
    std::cout << "Game over!" << std::endl;
    return 0;
}
