//Math tutor program by Andrew Brown 2/19/2018
//Updated for homework 5 on 3/17/2019

#include<iostream>
#include<iomanip>
#include<string>
#include <cstdlib>
#include <ctime>

using namespace std;

main()
{
	//randomize random number generator using current time
	srand(static_cast<unsigned int>(time(0)));
	
	//Declaring and initializing variables
	string p1="";
	int answer{0};
	string game_status="";
	unsigned int points{0};
	unsigned int x{0};
	unsigned int y{0};
	
	//Welcome message
	cout<<"Welcome to the multiplication table game!"<<endl;
	cout<<"This is an interactive program that can help you learn your multiplication tables\nand show you how well you know them!"<<endl;
	cout<<"Give it a try!"<<endl;
	
	//Get player name
	cout<<"\nPlease enter your first name: ";
	cin>>p1;
	
	//Prompt user to play game
	do
	{
		cout<<"Do you want to practice your multiplication tables? (Enter 'Yes' or 'No'): ";
		cin>>game_status;
		if ((game_status != "Yes") && (game_status != "No"))
		{
			cout<<"\nInvalid entry! Please enter 'Yes' or 'No'"<<endl;
		}
	}
	while ((game_status != "Yes") && (game_status != "No"));
	
	//Loop to play game until user enters 'No'
	while (game_status == "Yes")
	{
		points=0;
		//Loop through 12 rounds
		for (unsigned int i = 1; i <= 12; i++)
		{
			//Randomize x and y
			x = 1 + rand() % 12;
			y = 1 + rand() % 12;
						
			cout<<"\nWhat is "<<x<<" * "<<y<<"?: ";
			cin>>answer;
			if (answer == (x*y))
			{
				cout<<"Correct!"<<endl;
				points++;
			}
			else
			{
				cout<<"That not right! The correct answer was "<<(x*y)<<"."<<endl;
			}
		}
		cout<<"\n"<<p1<<", you scored "<<points<<"/12 points this round!"<<endl;
		
		//Ask user to replay or quit
		do
		{
			cout<<"Do you want to keep practicing your multiplication tables? (Enter 'Yes' or 'No'): ";
			cin>>game_status;
			if ((game_status != "Yes") && (game_status != "No"))
			{
				cout<<"\nInvalid entry! Please enter 'Yes' or 'No'"<<endl;
			}
		}
		while ((game_status != "Yes") && (game_status != "No"));	
	}
	//Ending message
	cout<<"\nThanks for playing, "<<p1<<"!\nSee you next time!"<<endl;
return(0);
}