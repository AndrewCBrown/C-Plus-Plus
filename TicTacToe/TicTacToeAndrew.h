// TicTacToe.h
#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <array>

class TicTacToe {
private:  
   enum Status {WIN, DRAW, CONTINUE}; // enumeration constants
   std::array<std::array<int, 3>, 3> board;
public:
   TicTacToe(); // default constructor
   void makeMove(); // make move
   void printBoard() const; // print board
   bool validMove(int, int) const; // validate move
   bool xoMove(int); // x o move 
   Status gameStatus() const; // game status
}; 

#endif


