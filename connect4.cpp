//Editor: Robert Church

#include <string>
#include <iostream>
#include <fstream>
#include "connect4.h"

using namespace std;

//Sets the board
connect4::connect4()
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 7; j++){
            if(i == 7)
            {
                board[i][j] = j+49;
            }
            else{
            board[i][j] = EMPTY;
            }
        }
    }

    for(int i = 0; i < 7; i++)
    {
        numDots[i] = 0;
    }

    player_ = 1;

    win_condition_ = 0;
}

//Prints the Board
void connect4::printBoard()
{
    for(int i = 0; i < 8; i++)
    {
            for(int j = 0; j < 7; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
    }
    cout<<endl;
}

//Introduction to the game
void connect4::welcomeConnect()
{
    cout<<"Welcome, to Connect 4!"<<endl<<endl;
    cout<<"I'm sure you've played before, but if you haven't here are the rules."<<endl;
    cout<<"1. If you get 4 in a row, you win!"<<endl;
    cout<<endl<<"Perfect! Now you've had your introduction so get out there and have some fun!"<<endl<<endl;
}

//returns number of dots in specific column
int connect4::getNumDotsAt(int index)
{
    return numDots[index];
}

//adds a dot to the specific column and updates numDots array as well as makes sure the column is on the board
int connect4::addDotAt(int index)
{

    if(index > 6 || index < 0)
    {
        cout<<"Please enter a valid column"<<endl;
        return -1;
    }

    if(numDots[index] == 7)
    {
        cout<<"It seems that column is full, please choose a different column"<<endl;
        return -1;
    }

    if(player_ == 1)
    {
        board[6-numDots[index]][index] = PLAYERONE;
        numDots[index]++;
        return 1;
    }
    if(player_ == 2)
    {
        board[6-numDots[index]][index] = PLAYERTWO;
        numDots[index]++;
        return 1;
    }

    return 0;
}

//checks if there are 4 in a row for horizontal, vertical, and diagonals
bool connect4::checkWin()
{
    //checks horizontal
    for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(board[i][j] == PLAYERONE && board[i][j+1] == PLAYERONE && board[i][j+2] == PLAYERONE  && board[i][j+3] == PLAYERONE)
                {
                    win_condition_ = 1;;
                }else
                if(board[i][j] == PLAYERTWO && board[i][j+1] == PLAYERTWO && board[i][j+2] == PLAYERTWO  && board[i][j+3] == PLAYERTWO)
                {
                    win_condition_ = 1;;
                }
            }
        }

    //checks win condition for vertical lines
    for(int j = 0; j < 7; j++)
    {
        for(int i = 0; i < 4; i++)
        {
            if(board[i][j] == PLAYERONE && board[i+1][j] == PLAYERONE && board[i+2][j] == PLAYERONE  && board[i+3][j] == PLAYERONE)
            {
                win_condition_ = 1;;
            }else
            if(board[i][j] == PLAYERTWO && board[i+1][j] == PLAYERTWO && board[i+2][j] == PLAYERTWO  && board[i+3][j] == PLAYERTWO)
            {
                win_condition_ = 1;;
            }
        }
    }

    //checks win condition for diagonals up and to the right
    for(int i = 3; i < 7; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == PLAYERONE && board[i-1][j+1] == PLAYERONE && board[i-2][j+2] == PLAYERONE && board[i-3][j+3] == PLAYERONE)
            {
                win_condition_ = 1;;
            }
            if(board[i][j] == PLAYERTWO && board[i-1][j+1] == PLAYERTWO && board[i-2][j+2] == PLAYERTWO && board[i-3][j+3] == PLAYERTWO)
            {
                win_condition_ = 1;;
            }
        }
    }

    //checks win condition for diagonals down and to the right
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == PLAYERONE && board[i+1][j+1] == PLAYERONE && board[i+2][j+2] == PLAYERONE && board[i+3][j+3] == PLAYERONE)
            {
                win_condition_ = 1;;
            }
            if(board[i][j] == PLAYERTWO && board[i+1][j+1] == PLAYERTWO && board[i+2][j+2] == PLAYERTWO && board[i+3][j+3] == PLAYERTWO)
            {
                win_condition_ = 1;;
            }
        }
    }

    return 0;

}

//changes players
void connect4::switchPlayer()
{
    if(player_ == 1)
    {
        player_ = 2;
    }else
    if(player_ == 2)
    {
        player_ = 1;
    }
}

//sets player
void connect4::setPlayer(int player)
{
    player_ = player;
}

//gets player
int connect4::getPlayer()
{
    return player_;
}

//gets win condition
bool connect4::getWinCondition()
{
    return win_condition_;
}

//checks if there is a draw
bool connect4::checkDraw()
{
    for(int i = 0; i < 7; i++)
    {
        if(numDots[i] != 7)
        {
            return 0;
        }
    }
    return 1;
}

//checks if a puck can be placed there for the computer
bool connect4::isPlacable(int row, int column)
{
    if(row == 6)
    {
        return 1;
    }else
    if(board[row+1][column] == PLAYERONE || board[row+1][column] == PLAYERTWO)
    {
        return 1;
    }
    return 0;
}

//checks if there is a row that the player could choose for the win
int connect4::isGonnaLose()
{
    //checking horizontal lines
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == EMPTY && board[i][j+1] == PLAYERONE && board[i][j+2] == PLAYERONE && board[i][j+3] == PLAYERONE && isPlacable(i, j))
            {
                return j;
            }
            if(board[i][j] == PLAYERONE && board[i][j+1] == EMPTY && board[i][j+2] == PLAYERONE && board[i][j+3] == PLAYERONE && isPlacable(i, j+1))
            {
                return j+1;
            }
            if(board[i][j] == PLAYERONE && board[i][j+1] == PLAYERONE && board[i][j+2] == EMPTY && board[i][j+3] == PLAYERONE && isPlacable(i, j+2))
            {
                return j+2;
            }
            if(board[i][j] == PLAYERONE && board[i][j+1] == PLAYERONE && board[i][j+2] == PLAYERONE && board[i][j+3] == EMPTY && isPlacable(i, j+3))
            {
                return j+3;
            }

        }
    }

    //checking for vertical lines
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(board[i][j] == EMPTY && board[i+1][j] == PLAYERONE && board[i+2][j] == PLAYERONE && board[i+3][j] == PLAYERONE && isPlacable(i, j))
            {
                return j;
            }
        }
    }

    //checks win condition for diagonals up and to the right with one space before
    for(int i = 3; i < 7; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == EMPTY && board[i-1][j+1] == PLAYERONE && board[i-2][j+2] == PLAYERONE && board[i-3][j+3] == PLAYERONE && isPlacable(i, j))
            {
                return j;
            }
            if(board[i][j] == PLAYERONE && board[i-1][j+1] == EMPTY && board[i-2][j+2] == PLAYERONE && board[i-3][j+3] == PLAYERONE && isPlacable(i-1, j+1))
            {
                return j+1;
            }
            if(board[i][j] == PLAYERONE && board[i-1][j+1] == PLAYERONE && board[i-2][j+2] == EMPTY && board[i-3][j+3] == PLAYERONE && isPlacable(i-2, j+2))
            {
                return j+2;
            }
            if(board[i][j] == PLAYERONE && board[i-1][j+1] == PLAYERONE && board[i-2][j+2] == PLAYERONE && board[i-3][j+3] == EMPTY && isPlacable(i-3, j+3))
            {
                return j+3;
            }
        }
    }

    //checks win condition for diagonals down and to the right
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == EMPTY && board[i+1][j+1] == PLAYERONE && board[i+2][j+2] == PLAYERONE && board[i+3][j+3] == PLAYERONE && isPlacable(i, j))
            {
                return j;
            }
            if(board[i][j] == PLAYERONE && board[i+1][j+1] == EMPTY && board[i+2][j+2] == PLAYERONE && board[i+3][j+3] == PLAYERONE && isPlacable(i+1, j+1))
            {
                return j+1;
            }
            if(board[i][j] == PLAYERONE && board[i+1][j+1] == PLAYERONE && board[i+2][j+2] == EMPTY && board[i+3][j+3] == PLAYERONE && isPlacable(i+2, j+2))
            {
                return j+2;
            }
            if(board[i][j] == PLAYERONE && board[i+1][j+1] == PLAYERONE && board[i+2][j+2] == PLAYERONE && board[i+3][j+3] == EMPTY && isPlacable(i+3, j+3))
            {
                return j+3;
            }
        }
    }

    return -1;
}

//checks if there is a row that the computer could choose for the win
int connect4::isGonnaWin()
{
    //checking horizontal lines
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == EMPTY && board[i][j+1] == PLAYERTWO && board[i][j+2] == PLAYERTWO && board[i][j+3] == PLAYERTWO && isPlacable(i, j))
            {
                return j;
            }
            if(board[i][j] == PLAYERTWO && board[i][j+1] == EMPTY && board[i][j+2] == PLAYERTWO && board[i][j+3] == PLAYERTWO && isPlacable(i, j+1))
            {
                return j+1;
            }
            if(board[i][j] == PLAYERTWO && board[i][j+1] == PLAYERTWO && board[i][j+2] == EMPTY && board[i][j+3] == PLAYERTWO && isPlacable(i, j+2))
            {
                return j+2;
            }
            if(board[i][j] == PLAYERTWO && board[i][j+1] == PLAYERTWO && board[i][j+2] == PLAYERTWO && board[i][j+3] == EMPTY && isPlacable(i, j+3))
            {
                return j+3;
            }

        }
    }

    //checking for vertical lines
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(board[i][j] == EMPTY && board[i+1][j] == PLAYERTWO && board[i+2][j] == PLAYERTWO && board[i+3][j] == PLAYERTWO && isPlacable(i, j))
            {
                return j;
            }
        }
    }

    //checks win condition for diagonals up and to the right with one space before
    for(int i = 3; i < 7; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == EMPTY && board[i-1][j+1] == PLAYERTWO && board[i-2][j+2] == PLAYERTWO && board[i-3][j+3] == PLAYERTWO && isPlacable(i, j))
            {
                return j;
            }
            if(board[i][j] == PLAYERTWO && board[i-1][j+1] == EMPTY && board[i-2][j+2] == PLAYERTWO && board[i-3][j+3] == PLAYERTWO && isPlacable(i-1, j+1))
            {
                return j+1;
            }
            if(board[i][j] == PLAYERTWO && board[i-1][j+1] == PLAYERTWO && board[i-2][j+2] == EMPTY && board[i-3][j+3] == PLAYERTWO && isPlacable(i-2, j+2))
            {
                return j+2;
            }
            if(board[i][j] == PLAYERTWO && board[i-1][j+1] == PLAYERTWO && board[i-2][j+2] == PLAYERTWO && board[i-3][j+3] == EMPTY && isPlacable(i-3, j+3))
            {
                return j+3;
            }
        }
    }

    //checks win condition for diagonals down and to the right
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == EMPTY && board[i+1][j+1] == PLAYERTWO && board[i+2][j+2] == PLAYERTWO && board[i+3][j+3] == PLAYERTWO && isPlacable(i, j))
            {
                return j;
            }
            if(board[i][j] == PLAYERTWO && board[i+1][j+1] == EMPTY && board[i+2][j+2] == PLAYERTWO && board[i+3][j+3] == PLAYERTWO && isPlacable(i+1, j+1))
            {
                return j+1;
            }
            if(board[i][j] == PLAYERTWO && board[i+1][j+1] == PLAYERTWO && board[i+2][j+2] == EMPTY && board[i+3][j+3] == PLAYERTWO && isPlacable(i+2, j+2))
            {
                return j+2;
            }
            if(board[i][j] == PLAYERTWO && board[i+1][j+1] == PLAYERTWO && board[i+2][j+2] == PLAYERTWO && board[i+3][j+3] == EMPTY && isPlacable(i+3, j+3))
            {
                return j+3;
            }
        }
    }

    return -1;    
}

//starts game between two real life opponents
void connect4::playerGame()
{
    int playerInput = 0; 
    bool winCondition = 0;

    welcomeConnect();
    while(!getWinCondition())
    {
        printBoard();
        cout<<"It's Player "<<getPlayer()<<"'s turn. What column do you want to put your dot in?"<<endl;
        cin>>playerInput;
        while(addDotAt(playerInput-1) == -1)
        {
            cin>>playerInput;
        }
        switchPlayer();

        checkWin();
        if(checkDraw() == 1)
        {
            printBoard();
            cout<<"It seems you drew. How did you manage that."<<endl;
            break;
        }
        if(getWinCondition())
        {
            printBoard();
            switchPlayer();
            cout<<"Player "<<getPlayer()<<" won. Good job player "<<getPlayer()<<"!"<<endl;
        }
    }
    
}

bool connect4::computerGame()
{
    srand(time(0));
    int playerInput = 0;
    int computerInput = 0;

    setPlayer(rand() % 2 + 1);
    welcomeConnect();
    cout<<"There's a 50% chance that I go first and a 50% chance that you go first."<<endl<<endl;

    while(!getWinCondition())
    {
        if(getPlayer() == 1)
        {
            printBoard();
            cout<<"It's your turn. What column do you want to put your dot in?"<<endl;
            cin>>playerInput;
            while(addDotAt(playerInput-1) == -1)
            {
                cin>>playerInput;
            }
        }else
        if(getPlayer() == 2)
        {
            computerInput = isGonnaWin();
            if(computerInput == -1)
            {
                computerInput = isGonnaLose();
            }
            if(computerInput == -1)
            {
                computerInput = rand() % 7;
                while(addDotAt(computerInput) == -1)
                {
                    computerInput = rand() % 7;
                }
                cout<<"It's my turn. I choose column "<<computerInput + 1<<"."<<endl<<endl;
                switchPlayer();
                continue;
            }
            addDotAt(computerInput);
            cout<<"It's my turn. I choose column "<<computerInput + 1<<"."<<endl<<endl;
        }
        switchPlayer();

        checkWin();
        if(checkDraw() == 1)
        {
            printBoard();
            cout<<"It seems we drew. How did we manage that."<<endl;
            cout<<"Game over. you win. I don't know."<<endl;
            break;
        }
        if(getWinCondition())
        {
            printBoard();
            switchPlayer();
            if(getPlayer() == 1)
            {
                cout<<"You won! Good Job!!!1!!"<<endl;
                return 1;
            }
            if(getPlayer() == 2)
            {
                cout<<"Oh. My. Goodness. You lost. To a computer. Embarasing really."<<endl;
                return 0;
            }

        }
    }
    return 0;
}
