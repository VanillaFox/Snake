#include <vector>

class Snake{
    private:
        std::vector<std::pair<int, int>> Tail;
        std::pair<int, int> Head;

    public:
        Snake(){}
        ~Snake();

        int HeadX();
        int HeadY();
        int TailX(int i);
        int TailY(int i);
        int TailSize();
        void NewCoord(int i, char c);
        void MoveTail();
        
        void IncreaseTail();
        bool CrashYourself();

        void NewHead(int &w, int &h);

};
