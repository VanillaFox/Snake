#include "game.h"
#include "input.h"

Map::Map(): Start(0){}
Map::~Map(){}

bool Map::Same(Snake &snake, Fruit &fruit){
    for(int i = 0; i < snake.TailSize(); i++){
        if(snake.TailX(i) == fruit.LastFruitX() && snake.TailY(i) == fruit.LastFruitY()){
            return true;
        }
    }
    return false;
}

void Map::TimeFruit(Snake &snake, Fruit &fruit){
    if((std::clock() - Start) / (double) CLOCKS_PER_SEC > 0.1){
        Start = std::clock();
        if(fruit.Size() < fruit.MaxSize()){
            fruit.AddFruit();
        }
        Check(snake, fruit);
    }
}

void Map::Horizontal(){
    for(int i = 0; i < Wedht; i++){
        std::cout << Wall;
    }
    NewLine();
}

void Map::MiddleMap(Snake &snake, Fruit &fruit){
    for (int i = 1; i < Height - 1; i++){
        for (int j = 0; j < Wedht; j++){
            if(DrawWall(j))
                continue;
            if(DrawHead(snake, i, j))
                continue;
            if(DrawFruit(fruit, i, j))
                continue;
            if(DrawTail(snake, i, j))
                continue;
            DrawPass();
        }
        NewLine();
    }
}

void Map::NewLine(){
    std::cout << std::endl;
}

void Map::DrawPass(){
    std::cout << " ";
}

bool Map::DrawWall(int &j){
    if(j == 0 || j == Wedht - 1){
        std::cout << Wall;
        return true;
    }
    return false;
}

bool Map::DrawHead(Snake &snake, int &i, int &j){
    if(j == snake.HeadX() && i == snake.HeadY()){
        std::cout << SHead;
        return true;
    }
    return false;
}


bool Map::DrawTail(Snake &snake, int &i, int &j){
    for(int k = 0; k < snake.TailSize(); k++){
        if(snake.TailX(k) == j && snake.TailY(k) == i){
            std::cout << STail;
            return true;
        }
    }
    return false;
}

bool Map::DrawFruit(Fruit &fruit, int &i, int &j){
    for (int k = 0; k < fruit.Size(); k++){
        if (fruit.FruitX(k) == j && fruit.FruitY(k) == i){
            std::cout << EFruit;
            return true;
        }
    }
    return false;
}


void Map::DrawMap(Snake &snake, Fruit &fruit){
    Horizontal();
    MiddleMap(snake, fruit);
    Horizontal();
}

void Map::NewSides(int &w, int &h){
    Wedht = w;
    Height = h;
}

void Map::Draw(Snake &snake, Fruit &fruit){
    TimeFruit(snake, fruit);
    DrawMap(snake, fruit);
}

void Map::Check(Snake &snake, Fruit &fruit){
    while(Same(snake, fruit)){
        fruit.NewCoordsForLast();
    }
}


void Game::Play(){
    while(!GameOver){
        Draw();
        Input();
        Move();
    }
}

void Game::Draw(){
    if(snake.CrashYourself()){
        dir = End;
        return;
    }

    int r = std::system("clear");

    map.Draw(snake, fruit);
    EatFruit();
    snake.MoveTail();
                    
    std::cout << "Score: " << Score << std::endl;
    usleep(65000);

}

void Game::EatFruit(){
    for(int i = 0; i < fruit.Size(); i++){
        if(snake.HeadY() == fruit.FruitY(i) && snake.HeadX() == fruit.FruitX(i)){
            snake.IncreaseTail();
            fruit.RewriteFruit(i);
            map.Check(snake, fruit);   
            Score += 15;
        } 
    }
}

void Game::Move(){
    switch(dir){
        case Left:
            if(snake.HeadX() == 1)
                GameOver = true;
            else
                snake.NewCoord(-1, 'x');           
            break;
        case Right:
            if(snake.HeadX() == wedht - 2)
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

void Game::Input(){
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
