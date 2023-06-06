//Program to play 8up

#include <iostream>
#include <iomanip>
#include <string>
#include "deckAndrew.h"

string showTop(Deck deck);
int topCardRank(Deck deck);
void PrintDeck(Deck deck);

int main()
{	
	//Get a new shuffled deck
	Deck mainDeck;
	mainDeck.GenerateDeck();
	for (int i = 0; i < 7; i++)
		{mainDeck.Shuffle();}
	mainDeck.ResetList();
	
	//Create an array of type Deck so that you can put 8 different decks into it (each of these decks will start out empty)
	Deck tableDecks[8];
	
	//Declare an array of type bool of length 8 and initialize all to true.
	bool pilesToDeal[8];
	
	//Other variables
	bool lost = true;
	int cardsDealt;
	Deck tempDeck;
	Card tempCard;
	bool test;
	string input = "";
	int gamesPlayed = 0;
	
	//Begin outer while loop
	while ((input != "stop") && lost)
	{
		gamesPlayed++;
		cout<<"\n"<<endl;
		
	
		//Set or Reset variables at the begining of the game
		cardsDealt = 0;
		lost = false;
		test = false;
		for (int i = 0; i < 8; i++)
			{pilesToDeal[i] = true;}

		//while loop that goes until the main deck is empty or lost==true.
		while ((cardsDealt < 52) && (lost == false))
		{
			//Print the top card of each deck (will be empty the first time)
			cout<<setw(20)<<showTop(tableDecks[0])<<setw(20)<<showTop(tableDecks[1])<<setw(20)<<showTop(tableDecks[2])<<setw(20)<<showTop(tableDecks[3])<<endl;
			cout<<setw(20)<<showTop(tableDecks[4])<<setw(20)<<showTop(tableDecks[5])<<setw(20)<<showTop(tableDecks[6])<<setw(20)<<showTop(tableDecks[7])<<endl;
			cout<<endl;

			//Deal new cards for the round.
			for (int i = 0; i < 8; i++) //Loop through the bool array and deal a card to each corresponding deck if the bool is true
			{
				if ((pilesToDeal[i] == true) && (cardsDealt < 52))
				{
					//Deal a card
					tempCard = mainDeck.GetNextItem();
					tableDecks[i].PutItem(tempCard);
					cardsDealt++;
				}
			}

			//Check for matches in the top cards of the table decks
			//Reset all bools in pilesToDeal to false
			for (int i = 0; i < 8; i++)
				{pilesToDeal[i] = false;}
			
			//Outer for loop that goes through each of the 8 table deck's top cards
			for (int i = 0; i < 8; i++)
			{
				//Inner loop that goes through the rest of the table deck's top cards (so each time this loop will be smaller)
				for (int j = i + 1; j < 8; j++)
				{
					//Compare the top card's ranks
					if (topCardRank(tableDecks[i]) == topCardRank(tableDecks[j]))
					{
						//set the bools at spots i and j both to true
						pilesToDeal[i] = true;
						pilesToDeal[j] = true;
					}
				}//End inner loop
			}//End outer loop

			//Flag for if we won't be able to deal any new cards next time.
			test = true;
			for (int i = 0; i < 8; i++)
			{
				if (pilesToDeal[i] == true)
				{test = false;}
			}
			if ((test) && (cardsDealt != 52)) //If we cannot deal to anymore piles and we still have cards left to deal
			{lost = true;}

		}//End while loop

		//Final print messages for the game
		//Print the top card of each deck
		cout<<setw(20)<<showTop(tableDecks[0])<<setw(20)<<showTop(tableDecks[1])<<setw(20)<<showTop(tableDecks[2])<<setw(20)<<showTop(tableDecks[3])<<endl;
		cout<<setw(20)<<showTop(tableDecks[4])<<setw(20)<<showTop(tableDecks[5])<<setw(20)<<showTop(tableDecks[6])<<setw(20)<<showTop(tableDecks[7])<<endl;
		cout<<endl;
		if (lost == false)
		{
			cout<<"\nCongratulations!!! You won!"<<endl;
			cout<<"You played "<<gamesPlayed<<" times."<<endl;
		}
		else
		{
			cout<<"You can't deal any more cards out!\nYou had "<<(52 - cardsDealt)<<" cards left."<<endl;
			cout<<"Better luck next time!"<<endl;
			
			//Tell user how many games played and ask to play again.
			cout<<"\nYou have played "<<gamesPlayed<<" times so far."<<endl;
			cout<<"Press any key and then enter to play again, or type 'stop' and press enter to quit.";
			cin>>input;
			
			if (input != "stop")
			{
				//Put all the decks back together and reshuffle them.
				cout<<"Shuffling the cards..."<<endl;
				mainDeck.ResetList();
				tempDeck.MakeEmpty();
				for (int i = 0; i < cardsDealt; i++)
				{
					mainDeck.GetNextItem();
				}
				for (int i = cardsDealt; i < 52; i++)
				{
					tempCard = mainDeck.GetNextItem();
					tempDeck.PutItem(tempCard);
				}
				for (int i = 0; i < 8; i++) //Pick the cards up off the table and put them back in main deck
				{
					tableDecks[i].ResetList();
					for (int j = 0; j < tableDecks[i].GetLength(); j++)
					{
						tempCard = tableDecks[i].GetNextItem();
						tempDeck.PutItem(tempCard);
					}
					tableDecks[i].MakeEmpty();
				}
				mainDeck.MakeEmpty();
				tempDeck.ResetList();
				for (int i = 0; i < 52; i++)
				{
					tempCard = tempDeck.GetNextItem();
					mainDeck.PutItem(tempCard);
				}
				//Shuffle mainDeck
				for (int i = 0; i < 7; i++)
					{mainDeck.Shuffle();}
				mainDeck.ResetList();
				cout<<"Shuffled deck:"<<endl;
				PrintDeck(mainDeck);
			}
		}
		
		
	}//End outer while loop
	cout<<"Thanks for playing 8up!"<<endl;
	
	return 0;
}//End main



string showTop(Deck deck) //Returns the top card of the deck as a string.
{
	string str;
	
	if (deck.GetLength() == 0)
	{str = "Empty";}
	
	else
	{
		deck.ResetList();
		Card card;
		for (int i = 0; i < deck.GetLength(); i++)
		{card = deck.GetNextItem();}
		str = card.ToString();
	}
	
	return str;
}

int topCardRank(Deck deck) //Returns the rank of the top card of the deck passed
{
	int rank;
	
	if (deck.GetLength() == 0)
	{
		cout<<"Error, you tried to get the rank of the top card of an empty deck."<<endl;
		rank = 0;
	}
	
	else
	{
		deck.ResetList();
		Card card;
		for (int i = 0; i < deck.GetLength(); i++)
		{card = deck.GetNextItem();}
		rank = card.GetRank();
	}
}

void PrintDeck(Deck deck) //Print deck function copied from deckDriver.cpp
{
  if (deck.GetLength() == 0)
     cout << "Deck is empty." << endl;
  else
  {
    deck.ResetList();
    Card card;
    for (int counter = 1; counter <= deck.GetLength(); counter++)
    {
      card = deck.GetNextItem();
      cout << card.ToString() << endl;
    }
  }
  cout << endl;
}