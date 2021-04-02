#include <vector>

class Fruit{
    private:
        std::vector<std::pair<int, int>> Fruits;
    public:
        Fruit();
        ~Fruit();
        
        int FruitsSize();
        int FruitX(int i);
        int FruitY(int i);
        int LastFruitX();
        int LastFruitY();


        void AddFruit();
        void RewriteFruit(int i);
        void NewCoordsForLast();
};
