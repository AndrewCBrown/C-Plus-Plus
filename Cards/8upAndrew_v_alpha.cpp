//First version will just play the game once, printing the 8 top cards after each move etc.
//Second version will play until a dub and count how many times it had to play.


//Original Algorithm for first version

//Get a new shuffled deck
//Create an array of type (deck type) so that you can put 8 different decks into it (each of these decks will start out empty)
//Declare an array of type bool of length 8 and initialize all to true.
//Declare a bool lost = false;


//{while loop that goes until the main deck is empty or lost==true.

//Print the top card of each deck (will be empty the first time)

//Deal new cards for the round.
//Loop through the bool array and deal a card to each corresponding deck if the bool is true, if false then don't deal to that deck.
	//(Note: you will have two checks before dealing each card, the bool must be true and the main deck must not be empty)
	//(If the bool is true but the deck is empty, you simply don't deal the card but just continue through this round as normal anyway)
	//(This works because you will have at least been able to add 1 new card since this loop won't execute if the deck was already empty.

//Now we check for matches
//Reset all bools to false
//Outter for loop that goes through the 8 decks top cards
	//Inner loop that goes through the rest of the decks top cards (so each time this loop will be smaller)(for int j = i+1; j < 8; j++)
		//Compare the top card's ranks
			//If they are equal
			//set the bools at spots i and j both to true.
			//If they are not equal we do nothing and just keep looping.
	//End inner loop
//End outter loop

//Flag for if we won't be able to deal any new cards next time.
//If all the bools are false, then set lost=true;
	//(Note: The special case where you ended up delaing out all the cards but don't have any matches after doing so)
	//(So only if all the bools are false and the main deck is not empty do you set lost=true, otherwise you'll do nothing, lost will still be
	//false and the deck will be empty so when the while loop tries to run again, it won't since the deck is empty and you'll get the win message)

//}End while loop

//Final print messages for the game
//If lost==false, print the top of each deck and say "congrats you won!"
//If lost==true, print the top of each deck and say "you can't deal any more cards out! Better luck nect time"
	//and print how many cards they had left in the main deck






#include <iostream>
#include <iomanip>
#include <string>
#include "cards/Deck.h"

string showTop(Deck deck);
int topCardRank(Deck deck);

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
	bool pilesToDeal[8] = {true, true, true, true, true, true, true, true};
	//Declare a bool lost = false;
	bool lost = false;
	int cardsDealt = 0;
	Card tempCard;
	bool test = false;


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
		
		//Outter for loop that goes through each of the 8 table deck's top cards
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
		}//End outter loop

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
	}
	else
	{
		cout<<"You can't deal any more cards out!\nYou had "<<(52 - cardsDealt)<<" cards left."<<endl;
		cout<<"Better luck next time!"<<endl;
	}
}



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