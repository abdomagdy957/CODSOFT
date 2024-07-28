
#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

enum Player{
     NONE = ' ', PLAYER_O = 'O', PLAYER_X = 'X'
};
void drawBoard(const char *squares);
void playerMove(char *squares, Player player);
void computerMove(char *squares, Player computer);
bool checkWinner(const char *squares, Player player);
bool checkDraw(const char *squares);

#endif
