#include <iostream>
#include "gameFunctions.h"
#include <cstdlib>
#include <ctime>


void drawBoard(const char *squares)
{
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << squares[0] << "  |  "<< squares[1] << "  |  " << squares[2] << "  "<< '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << squares[3] << "  |  "<< squares[4] << "  |  " << squares[5] << "  "<< '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << squares[6] << "  |  "<< squares[7] << "  |  " << squares[8] << "  "<< '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}
void playerMove(char *squares, Player player)
{
    int number;
    do
    {
        std::cout << "Please Enter a number (1-9): ";
        std::cin >> number;
        number--; // cuz we deal with array index from 0 to 8
        if(squares[number] == ' ')  // if there is an empty square
        {
            squares[number] = player;
            break;
        }
    }
    while(!number>0 || !number<9);  //if the number out of range don't exit from while and try again
}
void computerMove(char *squares, Player computer)
{
    int randomNumber;
    std::srand(std::time(nullptr)); // This ensures that you get different random numbers each time you repeat the loop
    while(true)
    {
        randomNumber = rand() % 9;  //generate random numbers from 0 to 9
        if(squares[randomNumber] == ' ')    // if there is an empty square
        {
            squares[randomNumber] = computer;
            break;
        }
    }
}
bool checkWinner(const char *squares, Player player)
{
    if((squares[0] != ' ') && (squares[0] == squares[1]) && (squares[1] == squares[2]))
    {
        squares[0] == player ? std::cout << "YOU WIN !!\n" : std::cout << "YOU LOSE !!\n";
    }
    else if((squares[3] != ' ') && (squares[3] == squares[4]) && (squares[4] == squares[5]))
    {
        squares[3] == player ? std::cout << "YOU WIN !!\n" : std::cout << "YOU LOSE !!\n";
    }
    else if((squares[6] != ' ') && (squares[6] == squares[7]) && (squares[7] == squares[8]))
    {
        squares[6] == player ? std::cout << "YOU WIN !!\n" : std::cout << "YOU LOSE !!\n";
    }
    else if((squares[0] != ' ') && (squares[0] == squares[3]) && (squares[3] == squares[6]))
    {
        squares[0] == player ? std::cout << "YOU WIN !!\n" : std::cout << "YOU LOSE !!\n";
    }
    else if((squares[1] != ' ') && (squares[1] == squares[4]) && (squares[4] == squares[7]))
    {
        squares[1] == player ? std::cout << "YOU WIN !!\n" : std::cout << "YOU LOSE !!\n";
    }
    else if((squares[2] != ' ') && (squares[2] == squares[5]) && (squares[5] == squares[8]))
    {
        squares[2] == player ? std::cout << "YOU WIN !!\n" : std::cout << "YOU LOSE !!\n";
    }

    else if((squares[0] != ' ') && (squares[0] == squares[4]) && (squares[4] == squares[8]))
    {
        squares[0] == player ? std::cout << "YOU WIN !!\n" : std::cout << "YOU LOSE !!\n";
    }
    else if((squares[2] != ' ') && (squares[2] == squares[4]) && (squares[4] == squares[6]))
    {
        squares[2] == player ? std::cout << "YOU WIN !!\n" : std::cout << "YOU LOSE !!\n";
    }
    else
    {
        return false;
    }
    return true;
}
bool checkDraw(const char *squares)
{
    for(int i{0}; i<9; i++)
    {
        if(squares[i] == ' ')
        {
            return false;   //still an empty square to be marker
        }
    }
    std::cout << "ITS A DRAW!\n";
    return true;
}
