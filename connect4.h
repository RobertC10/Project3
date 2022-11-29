//Editor: Robert Church

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class connect4
{
    private:
        const char PLAYERONE = 'X';
        const char PLAYERTWO = 'O';
        const char EMPTY = '-';

        static const int BoardHight = 8;
        static const int BoardWidth = 7;

        char board[BoardHight][BoardWidth];

        int numDots[7];
        int player_;
        bool win_condition_;

    public:
        connect4();
        void printBoard();
        void welcomeConnect();

        int getNumDotsAt(int);
        int addDotAt(int);
        void switchPlayer();
        void setPlayer(int);
        int getPlayer();
        bool getWinCondition();
        bool isPlacable(int, int);

        bool checkWin();
        bool checkDraw();
        int isGonnaLose();
        int isGonnaWin();

        void playerGame();
        bool computerGame();
        
        
};
