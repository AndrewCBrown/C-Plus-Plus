//Tortoise and Hare program (I only wrote the functions) by Andrew Brown 4/18/2019

#include <iostream> 
#include <random> // contains C++11 random number generation features
#include <ctime>
#include <cstdlib>
#include <iomanip> 
using namespace std;

const int RACE_END = 70;

// prototypes
void moveTortoise(int* const);
void moveHare(int* const);
void printCurrentPositions(const int* const, const int* const);

int main() {
   int tortoise{1};
   int hare{1};
   int timer{0};   
   
   //Setting a random seed
	srand(static_cast<unsigned int>(time(0)));

   cout << "ON YOUR MARK, GET SET\nBANG               !!!!"
      << "\nAND THEY'RE OFF    !!!!\n";
   
   // loop through the events
   while (tortoise != RACE_END && hare != RACE_END) {
      moveTortoise(&tortoise);
      moveHare(&hare);
      printCurrentPositions(&tortoise, &hare);
      ++timer;
   } 

   if (tortoise >= hare) {
      cout << "\nTORTOISE WINS!!! YAY!!!\n";
   }
   else {
      cout << "Hare wins. Yuch.\n";
   }

   cout << "TIME ELAPSED = " << timer << " seconds" << endl;
}




//Function definitions
// progress for the tortoise
void moveTortoise(int*  const turtlePtr) {
	static int move{0};
	move = 1 + rand() % 10;
	
	switch (move)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		*turtlePtr += 3;
		break;
		case 6:
		case 7:
		*turtlePtr -= 6;
		break;
		case 8:
		case 9:
		case 10:
		*turtlePtr += 1;
		break;
		default:
		cout<<"Program should not get here."<<endl;
		break;
	}
	//If tortoise is greater than 70, set it back to 70
	if (*turtlePtr > 70)
	{
		*turtlePtr = 70;
	}
	
	//Else if tortoise is less than 1, set it back to 1
	else if (*turtlePtr < 1)
	{
		*turtlePtr = 1;
	}
}  

// progress for the hare
void moveHare(int*  const rabbitPtr) {
	static int move{0};
	move = 1 + rand() % 10;
	
	switch (move)
	{
		case 1:
		case 2:
		//hare sleeps
		break;
		case 3:
		case 4:
		*rabbitPtr += 9;
		break;
		case 5:
		*rabbitPtr -= 12;
		break;
		case 6:
		case 7:
		case 8:
		*rabbitPtr += 1;
		break;
		case 9:
		case 10:
		*rabbitPtr -= 2;
		break;
		default:
		cout<<"Program should not get here."<<endl;
		break;
	}
	//If hare is greater than 70, set it back to 70
	if (*rabbitPtr > 70)
	{
		*rabbitPtr = 70;
	}
	
	//Else if hare is less than 1, set it back to 1
	else if (*rabbitPtr < 1)
	{
		*rabbitPtr = 1;
	}
}

// display new position
void printCurrentPositions(const int*  const snapperPtr, const int*  const bunnyPtr) {
	if (*snapperPtr > *bunnyPtr)
	{
		for (int i=0; i < (*bunnyPtr - 1); i++)
		{
			cout<<" ";
		}
		cout<<"H";
		for (int i=0; i < (*snapperPtr - *bunnyPtr - 1); i++)
		{
			cout<<" ";
		}
		cout<<"T"<<endl;
	}
	else
	{
		for (int i=0; i < (*snapperPtr - 1); i++)
		{
			cout<<" ";
		}
		cout<<((*snapperPtr == *bunnyPtr)? "OUCH!!!": "T");
		for (int i=0; i < (*bunnyPtr - *snapperPtr - 1); i++)
		{
			cout<<" ";
		}
		cout<<((*snapperPtr == *bunnyPtr)? "": "H")<<endl;
	}
} 