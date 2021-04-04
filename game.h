#include <iostream>
#include "fruit.h"
#include "snake.h"
#include <unistd.h>
#include <ctime>

class Map{
    private:
        const char Wall = '+';
        const char STail = '*';
        const char SHead = 'o';
        const char EFruit = '$';
        int Wedht, Height;
        std::clock_t Start;

        bool Same(Snake &snake, Fruit &fruit);
        void TimeFruit(Snake &snake, Fruit &fruit);
        void Horizontal();
        void DrawPass();
        void NewLine();
        void DrawMap(Snake &snake, Fruit &fruit);
        void MiddleMap(Snake &snake, Fruit &fruit);
        bool DrawWall(int &j);
        bool DrawHead(Snake &snake, int &i, int &j);
        bool DrawTail(Snake &snake, int &i, int &j);
        bool DrawFruit(Fruit &fruit, int &i, int &j);

    public:
        Map();
        ~Map();

        void NewSides(int &w, int &h);
        void Check(Snake &snake, Fruit &fruit);
        void Draw(Snake &snake, Fruit &fruit);
};

class Game{
    private:
        enum Directon {Stop = 0, Left, Right, Up, Down, End};

        Map map;
        Snake snake;
        Fruit fruit;
        int height, wedht, Score = 0;
        bool GameOver;
        Directon dir;

        void Draw();
        void EatFruit();
        void Move();
        void Input();

    public:
        void Play();
        Game(int a = 30, int b = 20): height(b), wedht(a), GameOver(false), dir(Stop){
            map.NewSides(a, b);
            snake.NewHead(a, b);
            fruit.NewSide(a, b);
            fruit.AddFruit();
        }

        ~Game(){
            std::cout << std::endl;
            std::cout << "Game Over!\n";
        }
};
