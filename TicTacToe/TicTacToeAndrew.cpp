//TicTacToe program by Andrew Brown 4/29/2019

#include <array>
#include <iostream>
#include <iomanip>
#include "TicTacToeAndrew.h"

using namespace std;


//Constructor //32 is space, 88 is X, 79 is O
TicTacToe::TicTacToe()
{
	for (unsigned int i=0; i < 3; i++)
	{
		for (unsigned int j=0; j < 3; j++)
		{
			board[i][j] = 32;
		}
	}
}


void TicTacToe::makeMove() // make move
{
   int turn{0};
   int row{0};
   int column{0};
   TicTacToe::Status status=CONTINUE;
   
   //Loop to run while status is continue
   while (status == CONTINUE)
   {
	   turn++;
	   
	   //print the board
	   printBoard();
	   
	   // tell the player who's turn it is to enter their move
	   cout<<"It is your turn "<<(xoMove(turn)?"player 1":"player 2")<<", you are "<<(xoMove(turn)?"X":"O")<<"'s."<<endl;
	   cout<<"Please enter your move by first entering the row number(0, 1, or 2) and then the column number(0, 1, or 2)."<<endl;
	   cout<<"What row number?: ";
	   cin>>row;
	   cout<<"\nWhat column number?: ";
	   cin>>column;
	   
	   //run valid move to check their move and make them reenter if not a valid move
	   while (!(validMove(row, column)))
	   {
		   cout<<"That spot is already taken! Try again."<<endl;
		   cout<<"What row number?: ";
		   cin>>row;
		   cout<<"\nWhat column number?: ";
		   cin>>column;
	   }
	   
	   board[row][column] = (xoMove(turn)?88:79);
	   
	   //update the game status by calling the function
	   status = gameStatus();
   }
   
   if(status == WIN)
   {
	   //print the board
	   printBoard();
	   cout<<(xoMove(turn)?"player 1":"player 2")<<" wins!"<<endl;
   }
   else
   {
	   //print the board
	   printBoard();
	   cout<<"Draw!! Good game."<<endl;
   }
}


void TicTacToe::printBoard() const // print board
{
   //print the x's, o's, space's, and lines between them
   cout<<"\n"<<endl;
   cout<<"      Col Col Col"<<endl;
   cout<<"       0   1   2 "<<endl;
   cout<<"         |   |   "<<endl;
   cout<<"Row 0: "<<static_cast<char>(board[0][0])<<" | "<<static_cast<char>(board[0][1])<<" | "<<static_cast<char>(board[0][2])<<" "<<endl;
   cout<<"         |   |   "<<endl;
   cout<<"      ---|---|---"<<endl;
   cout<<"         |   |   "<<endl;
   cout<<"Row 1: "<<static_cast<char>(board[1][0])<<" | "<<static_cast<char>(board[1][1])<<" | "<<static_cast<char>(board[1][2])<<" "<<endl;
   cout<<"         |   |   "<<endl;
   cout<<"      ---|---|---"<<endl;
   cout<<"         |   |   "<<endl;
   cout<<"Row 2: "<<static_cast<char>(board[2][0])<<" | "<<static_cast<char>(board[2][1])<<" | "<<static_cast<char>(board[2][2])<<" "<<endl;
   cout<<"         |   |   "<<endl;
}


bool TicTacToe::validMove(int row, int column) const // validate move
{
   //check the spot the player selected to see if it's a space or already taken
   if (board[row][column] == 32)
   {
	   return true;
   }
   else
   {
	   return false;
   }
}


bool TicTacToe::xoMove(int turn) // x o move
{
   if ((turn % 2) == 1)
   {
	   return true;
   }
   else
   {
	   return false;
   }	   
}


TicTacToe::Status TicTacToe::gameStatus() const // game status
{
   //Function to return the game status
   int r1=(board[0][0]+board[0][1]+board[0][2]);
   int r2=(board[1][0]+board[1][1]+board[1][2]);
   int r3=(board[2][0]+board[2][1]+board[2][2]);
   int c1=(board[0][0]+board[1][0]+board[2][0]);
   int c2=(board[0][1]+board[1][1]+board[2][1]);
   int c3=(board[0][2]+board[1][2]+board[2][2]);
   int d1=(board[0][0]+board[1][1]+board[2][2]);
   int d2=(board[0][2]+board[1][1]+board[2][0]);
   
   if ((r1 == 264) || (r1 == 237))
   {
	   return WIN;
   }
   
   else if ((r2 == 264) || (r2 == 237))
   {
	   return WIN;
   }
   
   else if ((r3 == 264) || (r3 == 237))
   {
	   return WIN;
   }
   
   else if ((c1 == 264) || (c1 == 237))
   {
	   return WIN;
   }
   
   else if ((c2 == 264) || (c2 == 237))
   {
	   return WIN;
   }
   
   else if ((c3 == 264) || (c3 == 237))
   {
	   return WIN;
   }
   
   else if ((d1 == 264) || (d1 == 237))
   {
	   return WIN;
   }
   
   else if ((d2 == 264) || (d2 == 237))
   {
	   return WIN;
   }
   
   else
   {
	   if ((r1 + r2 + r3) == 756)
	   {
		   return DRAW;
	   }
	   else
	   {
		   return CONTINUE;
	   }
   }
}