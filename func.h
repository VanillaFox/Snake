#include <iostream>
#include <unistd.h>
#include <time.h>

const int widht = 30;
const int height = 30;
extern bool GameOver;

void Draw();
void Setup();
void Logic();
void Input();