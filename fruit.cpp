#include "fruit.h"
#include <iostream>

Fruit::~Fruit(){
    Fruits.clear();
}

void Fruit::NewCoordsForLast(){
    Fruits[Fruits.size() - 1].first = rand() % (Wedht - 2) + 1;
    Fruits[Fruits.size() - 1].second = rand() % (Height - 2) + 1;
}


int Fruit::Size(){
    return Fruits.size();
}

int Fruit::MaxSize(){
    return maxSize;
}

int Fruit::FruitX(int i){
    return Fruits[i].first;
}

int Fruit::FruitY(int i){
    return Fruits[i].second;
}

int Fruit::LastFruitX(){
    return Fruits.back().first;
}

int Fruit::LastFruitY(){
    return Fruits.back().second;
}

void Fruit::AddFruit(){
    Fruits.push_back(std::make_pair(0, 0));
    NewCoordsForLast();
}

void Fruit::RewriteFruit(int i){
    Fruits.erase(Fruits.begin() + i);
    AddFruit();
}

void Fruit::NewSide(int &w, int &h){
    Wedht = w;
    Height = h;
}
