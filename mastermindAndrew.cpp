//Mastermind program by Andrew Brown 3/29/2019
//Program lets user play the mastermind game with 2 different difficulty modes

#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;


//Function prototypes
string welcome(); //Function to welcome player and get their name
void noobChecker(const string player); //Function to explain the game rules if necessary
string getDifficulty(); //Function to get the difficulty from the player, explains to the player what the different difficulties are.
void createKey(const size_t guess_array_size, const size_t colorList_array_size, char* const key, const char* const colorList); //Function to create the key, takes parameters created from the difficulty selection statement
void printGameBoard(const unsigned int round, const size_t guess_array_size, const unsigned int currentRound, const char* const guess, const string difficulty, const unsigned int partial_correct, const unsigned int full_correct, const bool won, const char* const key); //Function to print the game board
void getUserGuesses(const size_t guess_array_size, char* const guess, const string difficulty); //Function to get the user's guess
unsigned int checkPartialRights(const char* const key, const char* const guess, const size_t guess_array_size); //Function to compare guess to mastermind for partial rights
unsigned int checkFullRights(const char* const key, const char* const guess, const size_t guess_array_size); //Function to compare guess to mastermind for only full rights
void printEndGame(const bool won, const string player); //Function to print final message
void printWonQty(const unsigned int games_won, const unsigned int game_number); //Function to print how many games the player has won
bool askReplay(const string player); //Function to ask if player wants to replay


int main ()
{
	//Randomize random number generator using current time
	srand(static_cast<unsigned int>(time(0)));
	
	//Variables
	string player=""; //Variable for player name
	bool replay=true; //Variable for replaying the game
	unsigned int game_number{0}; //Variable for number of games played
	string difficulty=""; //Variable for the difficulty level
	size_t guess_array_size{0}; //Variable for the guess array size
	size_t colorList_array_size{0}; //Variable for the colorList array size
	const char colorList[8]{'R', 'O', 'Y', 'G', 'B', 'P', 'T', 'S'};  //Array with the list of colors
	unsigned int round{0}; //Variable for the number of rounds the player will play
	unsigned int partial_correct{0}; //Variable to record how many colors the user guessed correctly
	unsigned int full_correct{0}; //Variable to record how many colors the user guessed correctly in the correct spot
	bool won=false; //Variable to record whether the player wins or loses
	unsigned int games_won{0}; //Variable to keep track of how many games the player has won
	
	//Run function to welcome the player and ask for their name, and set equal to "player"
	player = welcome();
	
	//Run function to explain the game rules
	noobChecker(player);
	
	//While loop to run until the player doesn't want to replay
	while (replay)
	{
		won = false;
		game_number++; //Add 1 to "game_number"
	
		//Run function to ask the user what difficulty they want to play on
		difficulty = getDifficulty();
		cout<<"\n\n"<<endl;
		
		//Selection statement to set the "guess_array_size", "colorList_array_size", and "round" based on the difficulty selection
		if (difficulty == "easy")
		{
			guess_array_size = 4;
			colorList_array_size = 4;
			round = 10;
		}
		else
		{
			guess_array_size = 6;
			colorList_array_size = 8;
			round = 15;
		}
		
		char key[guess_array_size];
		char guess[guess_array_size];
		for (unsigned int i=0; i < guess_array_size; i++)
		{
			guess[i] = ' ';
		}
		
		//Run function to create the mastermind key
		createKey(guess_array_size, colorList_array_size, key, colorList);
		
		//For loop to run "round" times
		for (unsigned int currentRound{0}; currentRound < round; currentRound++)
		{			
			cout<<"~~~Round"<<setw(2)<<(currentRound + 1)<<"~~~"<<endl;
			//Run the function to get the user's guesses
			getUserGuesses(guess_array_size, guess, difficulty);
			
			//Run the function to see how many colors the player guessed correct and set equal to "partial_correct"
			partial_correct = checkPartialRights(key, guess, guess_array_size);
			//Run the function to see how many colors the player guessed in the correct spot and set equal to "full_correct"
			full_correct = checkFullRights(key, guess, guess_array_size);
			
			//Selection statement to see if player won
			if (full_correct == guess_array_size)
			{
				won = true;
				games_won++;
				printGameBoard(round, guess_array_size, currentRound, guess, difficulty, partial_correct, full_correct, won, key);
				break;
			}
			else
			{
				//Run the function to display the game board
				printGameBoard(round, guess_array_size, currentRound, guess, difficulty, partial_correct, full_correct, won, key);
			}
		}
		
		//Run function to print final message
		printEndGame(won, player);
		
		//Run the function to print how many games they have won
		printWonQty(games_won, game_number);
		
		//Run the function to ask if the player wants to play again
		replay = askReplay(player);
	}
	
	//Display closing message
	cout<<"Thanks for playing mastermind!\nSee you next time!"<<endl;
	
return 0;
}



//Function definitions

//"welcome"
string welcome()
{
	string player_name=""; //Declaring a variable local to the function to store the player's name
	cout<<"Welcome to the Mastermind game!"<<endl;
	cout<<"Please enter your name: ";
	cin>>player_name;
	cout<<"\nThanks for stopping by, "<<player_name<<"!"<<endl;
	cout<<"Why don't you go ahead and make sure that your window is full screen for the optimal experience and let's get started!"<<endl;
	return player_name;
}

//"noobChecker" 
void noobChecker(const string player)
{
	char noob='n'; //Declaring a variable local to the function to evaluate the user's choice
	
	cout<<"Would you like to know the game rules before we start or have you already played before and just want to get right into things?"<<endl;
	while (true) //While loop that runs until user gives valid input
	{
		cout<<"Enter 'y' if you want the rules explained, otherwise enter 'n': ";
		cin>>noob;
		cout<<endl;
		if ((noob == 'y') or (noob == 'n'))
		{
			break;
		}
		else
		{
			cout<<"That input was not valid!\nPlease enter 'y' or 'n'."<<endl;
		}
	}
	cout<<"\n"<<endl;
	
	if (noob == 'n') //If they entered 'n' then we skip explaining the rules
	{}

	else //If they entered 'y' then we explain the game rules here
	{
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MASTERMIND GAME RULES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"Mastermind is essentially a guessing game, with some critical thinking skills involved."<<endl;
		cout<<"At the beginning of the game the computer will generate a sequence of colors with no duplicate colors."<<endl;
		cout<<"You will not know what the colors are but you will be given a certain number of turns to figure it out."<<endl;
		cout<<"Each round you get to guess the sequence and you will get feedback on your guess."<<endl;
		cout<<"For every '#' you get, that represents that you guessed one of the colors in the sequence but you had it in the wrong spot."<<endl;
		cout<<"For every '*' you get, that represents that you guessed the correct color in the correct spot."<<endl;
		cout<<"However, the '#'s and '*'s will not be in an order relating to your guess, so if you guessed Red Yellow Green,\nand the sequence was Orange Yellow Silver, you would get one '*' but you won't know which of your guesses was the correct one."<<endl;
		cout<<"The game goes until you either guess the code correctly and win, or until you run out of guesses."<<endl;
		
		cout<<"\nLet's look at an example game so you can see how it all works."<<endl;
		cout<<"Below is an example board of someone playing on hard level who guessed the code correctly in 11 rounds.\n"<<endl;
		
		cout<<"=============================================="<<endl;
		cout<<"=         Your guesses         |    Result   ="<<endl;
		cout<<"=--------------------------------------------="<<endl;
		cout<<"= 1:  'R' 'O' 'Y' 'G' 'B' 'P'  |     #####   ="<<endl;
		cout<<"= 2:  'G' 'Y' 'O' 'R' 'T' 'S'  |      ####   ="<<endl;
		cout<<"= 3:  'B' 'B' 'R' 'O' 'Y' 'G'  |      ##**   ="<<endl;
		cout<<"= 4:  'R' 'R' 'R' 'R' 'R' 'R'  |         *   ="<<endl;
		cout<<"= 5:  'Y' 'Y' 'Y' 'Y' 'Y' 'Y'  |             ="<<endl;
		cout<<"= 6:  'P' 'B' 'R' 'O' 'G' 'S'  |     ####*   ="<<endl;
		cout<<"= 7:  'B' 'T' 'O' 'R' 'P' 'G'  |    ####**   ="<<endl;
		cout<<"= 8:  'B' 'T' 'O' 'P' 'R' 'G'  |    #####*   ="<<endl;
		cout<<"= 9:  'B' 'S' 'S' 'R' 'P' 'S'  |       #**   ="<<endl;
		cout<<"=10:  'B' 'G' 'R' 'O' 'P' 'T'  |    ##****   ="<<endl;
		cout<<"=11:  'B' 'R' 'G' 'O' 'P' 'T'  |    ******   ="<<endl;
		cout<<"=12:  ' ' ' ' ' ' ' ' ' ' ' '  |             ="<<endl;
		cout<<"=13:  ' ' ' ' ' ' ' ' ' ' ' '  |             ="<<endl;
		cout<<"=14:  ' ' ' ' ' ' ' ' ' ' ' '  |             ="<<endl;
		cout<<"=15:  ' ' ' ' ' ' ' ' ' ' ' '  |             ="<<endl;
		cout<<"=--------------------------------------------="<<endl;
		cout<<"=      B   R   G   O   P   T  <-- Mastermind ="<<endl;
		cout<<"=============================================="<<endl;
		
		cout<<"\nNotice the game ended after round 11 because the player guessed the correct code."<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF RULES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		//Next 3 lines pause program until user types anything to continue
		string foo="";
		cout<<"\nType any letter and then press enter to continue: ";
		cin>>foo;
	}
	cout<<"\nGreat! Looks like you've got the rules down, "<<player<<". Let's get started!"<<endl;
}
	
//"getDifficulty"
string getDifficulty()
{
	cout<<"There are two difficulty levels you can play on: Easy and Hard"<<endl;
	cout<<"Easy difficulty has a hidden sequence with 4 colors, chosen from this list: Red Orange Yellow Green (ROYG).\nAnd you get 10 rounds to guess the sequence."<<endl;
	cout<<"Hard difficulty has a hidden sequence with 6 colors, chosen from this list: Red Orange Yellow Green Blue Pink Tan Silver (ROYGBPTS).\nAnd you get 15 rounds to guess the sequence."<<endl;
	
	string diff=""; //Declaring a variable local to the function to store the player's difficulty selection
	while (true) //While loop that runs until user gives valid input
	{
		cout<<"Select your difficulty, enter 'easy' or 'hard': ";
		cin>>diff;
		cout<<endl;
		if ((diff == "easy") or (diff == "hard"))
		{
			break;
		}
		else
		{
			cout<<"That input was not valid, try again."<<endl;
		}
	}
	cout<<"\n"<<endl;
	return diff;
}

//"createKey"
void createKey(const size_t guess_array_size, const size_t colorList_array_size, char* const key, const char* const colorList)
{
	//Creating a local array that will store the random numbers later to be converted to colors.
	int keyTemp[guess_array_size]={0};
	bool reloop=true; //Control vairable for while loop used to make sure each random number is unique
	
	//for loop to create the key array but with numbers
	for (unsigned int i=0; i<guess_array_size; i++)
	{
		reloop=true;
		
		//while loop continues until a valid random number is entered into the keyTemp array (a valid value just means not a repeat of a number already in the array)
		while (reloop)
		{
			keyTemp[i] = rand() % colorList_array_size; //Puts a random number in keyTemp
			reloop=false;
			
			//for loop to check if the random number entered in keyTemp is equal to one of the numbers already in keyTemp, if it is, reloop will be set to true, meaning it will force the program to repick the random number.
			for (unsigned int j=0; j < i; j++)
			{
				if (keyTemp[i]==keyTemp[j])
				{
					reloop=true;
					break; //Break allows program to run slightly faster by not having to check every value once a repeat has already been found.
				}
			}
		}
	}
	
	//for loop converts keyTemp's values into the colors and stores them in the array "key"
	for (unsigned int i=0; i < guess_array_size; i++)
	{
		key[i] = colorList[keyTemp[i]];
	}
}

//"printGameBoard"
void printGameBoard(const unsigned int round, const size_t guess_array_size, const unsigned int currentRound, const char* const guess, const string difficulty, const unsigned int partial_correct, const unsigned int full_correct, const bool won, const char* const key)
{
	static char guesses[15][6]{}; //Creating the array for the main section of the game board. Note the array is set to the max size that will be needed in case player plays easy and then replays on hard
	static char feedback[15][6]{}; //Creating the array for the feedback side of the main section of the game board. Note the array is set to the max size that will be needed.
	//Selection statement to initialize both arrays to " ", (one space) only the first time the function is run each game
	if (currentRound == 0)
	{
		for (unsigned int i=0; i < round; i++)
		{
			for (unsigned int j=0; j < guess_array_size; j++)
			{
				guesses[i][j]=' ';
				feedback[i][j]=' ';
			}
		}
	}
	
	//Adding the user's guesses for the round into the array guesses
	for (unsigned int i=0; i < guess_array_size; i++)
	{
		guesses[currentRound][i] = guess[i];
	}
	
	//Adding the feedback for the user's guesses for the round into the array feedback
	for (unsigned int i=0; i < guess_array_size; i++)
	{
		if (i < (guess_array_size - partial_correct))
		{
			feedback[currentRound][i] = ' ';
		}
		else if (i < (guess_array_size - full_correct))
		{
			feedback[currentRound][i] = '#';
		}
		else
		{
			feedback[currentRound][i] = '*';
		}
	}
	
	//Print the gameboard header
	cout<<endl;
	if (difficulty == "easy")
	{
		cout<<"===================================="<<endl;
		cout<<"=     Your guesses     |   Result  ="<<endl;
		cout<<"=----------------------------------="<<endl;
	}
	else
	{
		cout<<"=============================================="<<endl;
		cout<<"=         Your guesses         |    Result   ="<<endl;
		cout<<"=--------------------------------------------="<<endl;
	}
	
	//Print the game board main section
	for (unsigned int i=0; i < round; i++)
	{
		cout<<"="<<setw(2)<<(i + 1)<<":  ";
		for (unsigned int j=0; j < guess_array_size; j++)
		{
			cout<<"'"<<guesses[i][j]<<"' ";
		}
		cout<<" |    ";
		for (unsigned int j=0; j < guess_array_size; j++)
		{
			cout<<feedback[i][j];
		}
		cout<<"   ="<<endl;
	}
	
	//Print the game board footer
	if (difficulty == "easy")
	{
		cout<<"=----------------------------------="<<endl;
		if (won or ((currentRound + 1) == round))
		{
			cout<<"=     ";
			for (unsigned int i=0; i < guess_array_size; i++)
			{
				cout<<" "<<key[i]<<"  ";
			}
			cout<<"<--Mastermind="<<endl;
		}
		else
		{
			cout<<"=      ?   ?   ?   ?  <--Mastermind="<<endl;
		}
		cout<<"===================================="<<endl;
	}
	else
	{
		cout<<"=--------------------------------------------="<<endl;
		if (won or ((currentRound + 1) == round))
		{
			cout<<"=     ";
			for (unsigned int i=0; i < guess_array_size; i++)
			{
				cout<<" "<<key[i]<<"  ";
			}
			cout<<"<-- Mastermind ="<<endl;
		}
		else
		{
			cout<<"=      ?   ?   ?   ?   ?   ?  <-- Mastermind ="<<endl;
		}
		cout<<"=============================================="<<endl;
	}
	
	cout<<"\n"<<endl;
}

//"getUserGuesses"
void getUserGuesses(const size_t guess_array_size, char* const guess, const string difficulty)
{
	char userGuess=' '; //Variable local to function to store the user's guess
	
	cout<<"Please enter your "<<guess_array_size<<" guesses each with the capital letter representing them."<<endl;
	cout<<"For example, to guess Red, enter 'R'."<<endl;
	for (unsigned int i=0; i < guess_array_size; i++)
	{		
		while (true) //While loop that runs until user gives valid input
		{
			cout<<"Guess #"<<(i + 1)<<": ";
			cin>>userGuess;
			if ((userGuess == 'R') or (userGuess == 'O') or (userGuess == 'Y') or (userGuess == 'G'))
			{
				break;
			}
			else if ((difficulty == "hard") and ((userGuess == 'B') or (userGuess == 'P') or (userGuess == 'T') or (userGuess == 'S')))
			{
				break;
			}
			else
			{
				cout<<"\nThat input was not valid, remember hard uses (ROYGBPTS), but easy only uses (ROYG).\nPlease try again."<<endl;
			}
		}
		
		guess[i] = userGuess;
		cout<<endl;
	}
}

//"checkPartialRights"
unsigned int checkPartialRights(const char* const key, const char* const guess, const size_t guess_array_size)
{
	unsigned int correct{0}; //Variable local to function to store the number of partial corrects
	bool check=true; //Variable local to function that will make sure to only check guesses that aren't repeats
	
	for (unsigned int i=0; i < guess_array_size; i++)
	{
		check=true;
		
		//for loop to make sure the current guess being iterated through is unique
		for (unsigned int j=0; j < i; j++)
		{
			if (guess[i] == guess[j])
			{
				check=false;
				break;
			}
		}
		
		if (check) //if check is true then we execute the foor loop to see if the user's color guessed matched any of the colors in the key
		{
			for (unsigned int j=0; j < guess_array_size; j++)
			{
				if (key[j] == guess[i])
				{
					correct++;
					break;
				}
			}
		}
	}
	
	return correct;
}

//"checkFullRights"
unsigned int checkFullRights(const char* const key, const char* const guess, const size_t guess_array_size)
{
	unsigned int correct{0}; //Variable local to function to store the number of full corrects
	
	for (unsigned int i=0; i < guess_array_size; i++)
	{
		if (key[i] == guess[i])
		{
			correct++;
		}
	}
	
	return correct;
}

//"printEndGame"
void printEndGame(const bool won, const string player)
{
	if (won)
	{
		cout<<"Congratulations "<<player<<"! You beat the mastermind!"<<endl;
	}
	else
	{
		cout<<"The mastermind could not be beaten!! Better luck next time, "<<player<<"!"<<endl;
	}
	
	cout<<"\n"<<endl;
}

//"printWonQty"
void printWonQty(const unsigned int games_won, const unsigned int game_number)
{
	cout<<"You have won "<<games_won<<" out of "<<game_number<<" games."<<endl;
}

//"askReplay"
bool askReplay(const string player)
{
	string user_replay=""; //Variable local to function to store user's choice of replaying the game

	cout<<"Would you like to play again, "<<player<<"?"<<endl;
	while (true) //While loop that runs until user gives valid input
	{
		cout<<"Enter 'y' or 'n': ";
		cin>>user_replay;
		cout<<endl;
		if ((user_replay == "y") or (user_replay == "n"))
		{
			break;
		}
		else
		{
			cout<<"That input was not valid, try again."<<endl;
		}
	}
	
	if (user_replay == "y")
	{
		return true;
	}
	else
	{
		return false;
	}
}









//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BELOW IS JUST NOTES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/* Specific Easy game board, the answers at the bottom should be '?' during play
Each '#' represents a color you guessed correctly but in the wrong spot
Each '*' represents a color you guessed correctly in the correct spot
====================================
=     Your guesses     |   Result  =
=----------------------------------=	
= 1:  'R' 'B' 'O' 'Y'  |     ###   =
= 2:  'P' 'O' 'B' 'Y'  |      ##   =
= 3:  'Y' 'P' 'O' 'R'  |      ##   =
= 4:  'B' 'R' 'Y' 'T'  |      **   =
= 5:  'B' 'R' 'O' 'P'  |     #**   =
= 6:  'B' 'R' 'I' 'O'  |     ***   =
= 7:  'B' 'R' 'G' 'O'  |    ****   =
= 8:  ' ' ' ' ' ' ' '  |           =
= 9:  ' ' ' ' ' ' ' '  |           =
=10:  ' ' ' ' ' ' ' '  |           =
=----------------------------------=
=      B   R   G   O  <--Mastermind=
====================================
*/

/* Specific hard game board, the answers at the bottom should be '?' during play
Each '#' represents a color you guessed correctly but in the wrong spot
Each '*' represents a color you guessed correctly in the correct spot
==============================================
=         Your guesses         |    Result   =
=--------------------------------------------=	
= 1:  'R' 'B' 'O' 'Y' 'I' 'T'  |     ###**   =
= 2:  'P' 'O' 'B' 'Y' 'I' 'T'  |      ##**   =
= 3:  'Y' 'P' 'O' 'R' 'I' 'T'  |      ##**   =
= 4:  'B' 'R' 'Y' 'S' 'I' 'T'  |      ****   =
= 5:  'B' 'R' 'O' 'P' 'I' 'T'  |     #****   =
= 6:  'B' 'R' 'S' 'O' 'I' 'T'  |     *****   =
= 7:  'B' 'R' 'G' 'O' 'I' 'T'  |    ******   =
= 8:  ' ' ' ' ' ' ' ' ' ' ' '  |             =
= 9:  ' ' ' ' ' ' ' ' ' ' ' '  |             =
=10:  ' ' ' ' ' ' ' ' ' ' ' '  |             =
=11:  ' ' ' ' ' ' ' ' ' ' ' '  |             =
=12:  ' ' ' ' ' ' ' ' ' ' ' '  |             =
=13:  ' ' ' ' ' ' ' ' ' ' ' '  |             =
=14:  ' ' ' ' ' ' ' ' ' ' ' '  |             =
=15:  ' ' ' ' ' ' ' ' ' ' ' '  |             =
=--------------------------------------------=
=      B   R   G   O   I   T  <-- Mastermind =
==============================================
*/

/*List of spots with input:
1. Getting player name in "welcome" function
2. Getting noob status in "noobChecker" function 
2.5 the foo input to continue screen
3. Getting difficulty in "getDifficulty" function
4. Getting the user's guesses in "getUserGuesses" function
5. Getting the replay status in "askReplay" function
*/


//Old original version 1 algorithm written out
//Create a boolean variable won
//Welcome the user (ask for player name etc.)
//Loop to play game until player chooses to exit
	//Ask user what difficulty they want (easy or hard)
		//I want to try to use the same main code so maybe have the process of setting up the game
		//just use different size arrays and different initializations for the number of turns and stuff
	//Set up the game board
		//Randomly create the mastermind key by using the different colors without repeat colors
	//Create a loop for the number of guesses of the player, loop will either terminate when they run out of guesses or when they win
		//Display the game board so far with what they have guessed and what information they got back
		//Ask the user for their guess
		//Check to see how many colors they guessed correct
		//Check to see how many colors they got right also in the right spot
		//either have a selection statement to set won to true and break if they guessed correct
			//or set a variable to something so the loop is broken when checked for a win
			//On that note it is probably gonna be faster to just break so you don't have to check an extra variable everytime the loop executes.
			//Unless you can make the loop condition to work so it evaluates the variable first
		//End loop?
	//Display their final game board with the victory message or with the failure message.
	//Ask if they want to play again or exit
	//Could either do no error checking, string error checking, or somehow create a template for error checking so it accepts all entries but keeps asking until valid
//Display closing message