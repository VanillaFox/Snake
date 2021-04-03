#include <vector>

class Fruit{
    private:
        std::vector<std::pair<int, int>> Fruits;
        int Wedht, Height;
        int maxSize;
    public:
        Fruit(int i = 3): maxSize(i){}
        ~Fruit();
        
        int Size();
        int MaxSize();
        int FruitX(int i);
        int FruitY(int i);
        int LastFruitX();
        int LastFruitY();

        void AddFruit();
        void RewriteFruit(int i);
        void NewCoordsForLast();
        void NewSide(int w, int h){
            Wedht = w;
            Height = h;
        }
};
