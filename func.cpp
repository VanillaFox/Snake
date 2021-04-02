#include "func.h"
#include "input.h"
#include <vector>
#include <ctime>

bool GameOver;

int x = widht / 2;
int y = height / 2;
int Score = 0;

std::vector<std::pair<int, int>> Tail, Fruit;

void NewX(int &x){
    x = rand() % (widht - 2) + 1;
}

void NewY(int &y){
    y = rand() % (height - 2) + 1;
}
void NewCoordsFruit(std::pair<int, int> & item){
    NewX(item.first);
    NewY(item.second);
}



enum Directon {Stop = 0, Left, Right, Up, Down, End};
Directon dir = Stop;

std::clock_t start = 0;

void Draw(){

    for(int i = 0; i < Tail.size(); i++){
        if(Tail[i].first == x && Tail[i].second == y){
            dir = End;
            return;
        }
    }

    int r = std::system("clear");

    if(( std::clock() - start ) / (double) CLOCKS_PER_SEC > 0.1){
        start = std::clock();
        if(Fruit.size() < 3){
            Fruit.push_back(std::make_pair(0, 0));
            NewCoordsFruit(Fruit[Fruit.size() - 1]);
        }
    }
    for(int i = 0; i < widht; i++){
        std::cout << "+";
    }

    std::cout << std::endl;

    for(int i = 1; i < height - 1; i++){
        for(int j = 0; j < widht; j++){
            if(j == 0 || j == widht - 1){
                std::cout << "|";
            }
            else if(j == x && i == y){
                std::cout << "o";
            }
            else{
                bool haveTail = false;
                bool haveFruit = false;
                for(int k = 0; k < Tail.size(); k++){
                    if(Tail[k].first == j && Tail[k].second == i){
                        std::cout << "*";
                        haveTail = true;
                    }
                }
                if(!haveTail){
                    for(int k = 0; k < Fruit.size(); k++){
                        if(Fruit[k].first == j && Fruit[k].second == i){
                            std::cout << "$";
                            haveFruit = true;
                        }
                    }
                }
                if(!(haveTail || haveFruit)){
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < widht; i++){
        std::cout << "+";
    }

    std::cout << std::endl;
    for(int i = 0; i < Fruit.size(); i++){
        if(y == Fruit[i].second && x == Fruit[i].first){
            Tail.push_back(std::make_pair(0, 0));
            NewCoordsFruit(Fruit[i]);
            Score += 15;
        }
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
    usleep(65000);
}

void Setup(){
    GameOver = false;
    Fruit.push_back(std::make_pair(0, 0));
    NewCoordsFruit(Fruit[0]);
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
            if(y == height - 2)
                GameOver = true;
            else
                y++; 
            break;
        case End:
            GameOver = true;
            break;
    }
}
