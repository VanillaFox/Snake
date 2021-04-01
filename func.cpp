#include "func.h"
#include "input.h"
#include <vector>

bool GameOver;

int x = widht / 2;
int y = height / 2;
int FruitX = 20;
int FruitY = 15;
int Score = 0;

std::vector<std::pair<int, int>> Tail;

void NewCoordsFruit(){
    FruitX = rand() % (widht - 2) + 1;
    FruitY = rand() % (height - 2) + 1;
}

enum Directon {Stop = 0, Left, Right, Up, Down, End};
Directon dir = Stop;

void Draw(){
    int r = std::system("clear");

    for(int i = 0; i < widht; i++){
        std::cout << "-";
    }

    std::cout << std::endl;

    for(int i = 1; i < height - 1; i++){
        for(int j = 0; j < widht; j++){
            if(j == 0 || j == widht - 1){
                std::cout << "|";
            }
            else if(j == x && i == y){
                std::cout << "o";
            }else if(j == FruitX && i == FruitY){
                std::cout << "$";
            }
            else{
                bool haveTail = false;
                for(int k = 0; k < Tail.size(); k++){
                    if(Tail[k].first == j && Tail[k].second == i){
                        std::cout << "*";
                        haveTail = true;
                    }
                }
                if(!haveTail){
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < widht; i++){
        std::cout << "-";
    }
    std::cout << std::endl;
    //if(x == 0 || x == widht - 1 || y == 0 || y == height - 1){
     //   dir = End;
   // }
    if(y == FruitY && x == FruitX){
        Tail.push_back(std::make_pair(0, 0));
        NewCoordsFruit();
        Score += 15;
    }
    int a, b, a1, b1;
    a = x;
    b = y;
    for(int i = 0; i < Tail.size(); i++){
        a1 = Tail[i].first;
        b1 = Tail[i].second;
        Tail[i].first = a;
        Tail[i].second = b;
        a = a1;
        b = b1;
    }
    std::cout << "Score: " << Score << std::endl;
    usleep(55000);
    //delay(5000);
}

void Setup(){
    GameOver = false;   
    NewCoordsFruit();
}

void Input(){
    if(kbhit()){
        switch (getch()){
            case 'a':
                dir = Left;
                break;
            case 's':
                dir = Down;
                break;
            case 'd':
                dir = Right;
                break;
            case 'w':
                dir = Up;
                break;
            case 'q':
                GameOver = true;
                break;
        }

    }
}

void Logic(){
    switch(dir){
        case Left:
            if(x == 1)
                GameOver = true;
            else
                x--;            
            break;
        case Right:
            if(x == widht - 2)
                GameOver = true;
            else
                x++;            
            break;
        case Up:
            if(y == 1)
                GameOver = true;
            else
                y--;
            break;
        case Down:
            if(y == height - 1)
                GameOver = true;
            else
                y++; 
            break;
        //case End:
          //  GameOver = true;
            //break;
    }
}
