#include "fruit.h"
#include "func.h"
#include <iostream>

Fruit::Fruit(){}

Fruit::~Fruit(){
    Fruits.clear();
}

void Fruit::NewCoordsForLast(){
    Fruits[Fruits.size() - 1].first = rand() % (widht - 2) + 1;
    Fruits[Fruits.size() - 1].second = rand() % (height - 2) + 1;
}

int Fruit::FruitsSize(){
    return Fruits.size();
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
