#include "func.h"
#include "input.h"
#include <vector>
#include <ctime>
#include "snake.h"
#include "fruit.h"

bool GameOver;
Snake snake;
Fruit fruit;
int Score = 0;

bool same(){
    for(int i = 0; i < snake.TailSize(); i++){
        if(snake.TailX(i) == fruit.LastFruitX() && snake.TailY(i) == fruit.LastFruitY()){
           return true;
        }
    }
    return false;
}

void check(){
    while(same()){
        fruit.NewCoordsForLast();
    }
}

enum Directon {Stop = 0, Left, Right, Up, Down, End};
Directon dir = Stop;

std::clock_t start = 0;

void Map(){

    if(snake.CrashYourself()){
        dir = End;
        return;
    }

    int r = std::system("clear");

    if(( std::clock() - start ) / (double) CLOCKS_PER_SEC > 0.1){
        start = std::clock();
        if(fruit.FruitsSize() < 3){
            fruit.AddFruit();
        }
        check();

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
            else if(j == snake.HeadX() && i == snake.HeadY()){
                std::cout << "O";
            }
            else{
                bool haveTail = false;
                bool haveFruit = false;
                for(int k = 0; k < snake.TailSize(); k++){
                    if(snake.TailX(k) == j && snake.TailY(k) == i){
                        std::cout << "*";
                        haveTail = true;
                    }
                }
                if(!haveTail){
                    for(int k = 0; k < fruit.FruitsSize(); k++){
                        if(fruit.FruitX(k) == j && fruit.FruitY(k) == i){
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
    for(int i = 0; i < fruit.FruitsSize(); i++){
        if(snake.HeadY() == fruit.FruitY(i) && snake.HeadX() == fruit.FruitX(i)){
            snake.IncreaseTail();
            fruit.RewriteFruit(i);
            check();
            Score += 15;
        }
    }
    snake.MoveTail();
    
    std::cout << "Score: " << Score << std::endl;
    usleep(65000);
}

void Setup(){
    GameOver = false;
    fruit.AddFruit();
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
            if(snake.HeadX() == 1)
                GameOver = true;
            else
                snake.NewCoord(-1, 'x');           
            break;
        case Right:
            if(snake.HeadX() == widht - 2)
                GameOver = true;
            else
                snake.NewCoord(1, 'x');           
            break;
        case Up:
            if(snake.HeadY() == 1)
                GameOver = true;
            else
                snake.NewCoord(-1, 'y');           
            break;
        case Down:
            if(snake.HeadY() == height - 2)
                GameOver = true;
            else
                snake.NewCoord(1, 'y');
            break;
        case End:
            GameOver = true;
            break;
    }
}
