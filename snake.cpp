#include <iostream>
#include "snake.h"

Snake::~Snake(){
    Tail.clear();
}

void Snake::IncreaseTail(){
    Tail.push_back(std::make_pair(0, 0));
}

int Snake::HeadX(){
    return Head.first;
}

int Snake::HeadY(){
    return Head.second;
}

int Snake::TailX(int i){
    return Tail[i].first;
}

int Snake::TailY(int i){
    return Tail[i].second;
}


int Snake::TailSize(){
    return Tail.size();
}

bool Snake::CrashYourself(){
    for(int i = 0; i < Tail.size(); i++){
        if(Tail[i].first == Head.first && Tail[i].second == Head.second){
            return true;
        }
    }
    return false;
}

void Snake::MoveTail(){
    int a, b, a1, b1;
    a = Head.first;
    b = Head.second;

    for(int i = 0; i < Tail.size(); i++){
        a1 = Tail[i].first;
        b1 = Tail[i].second;
        Tail[i].first = a;
        Tail[i].second = b;
        a = a1;
        b = b1;
    }
}

void Snake::NewCoord(int i, char c){
    if(c == 'x')
        Head.first += i;
    else
        Head.second += i;
}
