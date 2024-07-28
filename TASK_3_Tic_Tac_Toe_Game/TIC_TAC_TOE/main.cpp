#include <iostream>
#include "gameFunctions.h"

int main()
{
    std::cout << "Welcome To The TIC TAC TOE Game: \n\n";
    char squares[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    Player player = PLAYER_O;       // creating an object from Player
    Player computer = PLAYER_X;
    bool isRunning {true};

    drawBoard(squares);
    while(isRunning)
    {
        /**now player move and the checking of winner or draw**/
        playerMove(squares,player);
        drawBoard(squares);
        if(checkWinner(squares,player))
        {
            isRunning = false;
            break;
        }
        else if(checkDraw(squares))
        {
            // now if the game has ended and no enough squares without anyone win
            isRunning = false;
            break;
        }

        /**now computer move and the checking of winner or draw**/
        computerMove(squares,computer);
        drawBoard(squares);
        if(checkWinner(squares,player))
        {
            isRunning = false;
            break;
        }
        else if(checkDraw(squares))
        {
            // now if the game has ended and no enough squares without anyone win
            isRunning = false;
            break;
        }
    }
}
