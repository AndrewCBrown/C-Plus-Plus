// Implementation file for class Deck, which
// represents a collection of 52 bridge cards.
#include <iostream>
#include "deckAndrew.h"
#include <cstdlib>
#include <time.h>

Deck::Deck()
// The UnsortedType constructor is called.
{}

void Deck::GenerateDeck()
// Generates deck in bridge (poker) order
{
  MakeEmpty();
  for(Suits suit = CLUB; suit <= SPADE; suit = Suits(suit+1))
    for(int value = 1; value <= 13; value++)
       PutItem(Card(value, suit));	
}

Deck Merge(Deck leftDeck, Deck rightDeck)
// Merges two decks, one card at a time, until first
// deck is empty.  Rest of second deck is appended.
//New method merges decks by randomly dropping cards from each side, an almost exact representation of how a human bridge shuffles.
{
	/*Old Definition
  Deck deck;
  Card card;
  int counter;
  shorterDeck.ResetList();
  longerDeck.ResetList();
  for (counter = 1; counter <= shorterDeck.GetLength();
    counter++)
  {
    card = shorterDeck.GetNextItem();
	deck.PutItem(card);
    card = longerDeck.GetNextItem();
    deck.PutItem(card);
  }
  int remaining = longerDeck.GetLength() - shorterDeck.GetLength();
  for (counter = 1; counter <= remaining; counter++)
  {
    card =longerDeck.GetNextItem();
    deck.PutItem(card);
  } 
  return deck;
  
  End Old Definition*/
  
  /*New Definition*/
  srand(time(NULL));  
  Deck deck;
  Card card;
  int counter;
  int drop;
  int leftDropped = 0;
  int rightDropped = 0;
  int i;
  int randomNum;
  leftDeck.ResetList();
  rightDeck.ResetList();
  
  while (deck.GetLength() < 52)
  {	  
	  //Pull cards from rightDeck to put in deck
	  randomNum = (rand() % 1000) + 1;
	  if ((randomNum >= 1) && (randomNum <= 533))
	  {
		  drop = 1;
	  }
	  else if ((randomNum >= 534) && (randomNum <= 903))
	  {
		  drop = 2;
	  }
	  else if ((randomNum >= 904) && (randomNum <= 988))
	  {
		  drop = 3;
	  }
	  else if ((randomNum >= 989) && (randomNum <= 1000))
	  {
		  drop = 4;
	  }
	  //Drop was assigned based on real data collected from my shuffles to simulate my shuffle.
	  i = 0;
	  while ((i < drop) && (rightDropped < rightDeck.GetLength()))
	  {
		  card = rightDeck.GetNextItem();
		  deck.PutItem(card);
		  rightDropped++;
		  i++;
	  }
	  
	  //Pull cards from leftDeck to put in deck
	  randomNum = (rand() % 1000) + 1;
	  if ((randomNum >= 1) && (randomNum <= 533))
	  {
		  drop = 1;
	  }
	  else if ((randomNum >= 534) && (randomNum <= 903))
	  {
		  drop = 2;
	  }
	  else if ((randomNum >= 904) && (randomNum <= 988))
	  {
		  drop = 3;
	  }
	  else if ((randomNum >= 989) && (randomNum <= 1000))
	  {
		  drop = 4;
	  }
	  //Drop was assigned based on real data collected from my shuffles to simulate my shuffle.
	  i = 0;
	  while ((i < drop) && (leftDropped < leftDeck.GetLength()))
	  {
		  card = leftDeck.GetNextItem();
		  deck.PutItem(card);
		  leftDropped++;
		  i++;
	  }
  }
  
  return deck;
  
  /*End New Definition*/
}
    
void Deck::Shuffle()
// Spilts deck into two parts, using random number generator
// to determine size of parts.  Parts are merged one card
// at a time, using helper function Merge.
{
  srand(time(NULL));
  Deck deckA;
  Deck deckB;
  Card card;
  ResetList();
  int splitSize;
  int counter;
  splitSize = ((rand() % 6) + 1) + 23;
  
  for (counter = 1; counter <= splitSize; counter++)
  {
    card = GetNextItem();
    deckA.PutItem(card);
  }
 
  for (counter = splitSize+1; counter <= GetLength();
    counter ++)
  {
    card = GetNextItem();
    deckB.PutItem(card);
  }
 
  MakeEmpty();
  *this = Merge(deckA, deckB);
  
  /* Old code for when merge needed to know which deck was bigger, new merge does not care.
  if (splitSize < (52 - splitSize))
    *this = Merge(deckA, deckB);
  else
    *this = Merge(deckB, deckA);

  End Old code*/
 }
