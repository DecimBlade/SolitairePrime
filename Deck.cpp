#include <iostream>
#include <string>
#include "Deck.h"
#include "Card.h"
using namespace std;


// 'T' is going to represent 10 and then I will use a pointer to convert it
char rankList[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
char suitList[4] = {'S', 'H', 'D', 'C'};

// Constructor
Deck::Deck(){
  // Implement for loop to iterate through both arrays and create a deck
  topCard = 0;
  int counter = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 13; j++){
      Card card = Card(rankList[j], suitList[i]);
      deck[counter++] = card;
    }
  }
}

// Reset the deck so it looks like a new deck
void Deck::refreshDeck(){
  topCard = 0;
  int counter = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 13; j++){
      Card card = Card(rankList[j], suitList[i]);
      deck[counter++] = card;
    }
  }
}

// Deals a card from the top of the deck
Card Deck::deal(){
  if(topCard < 52){
    return deck[topCard++];
  }
  else{
    return Card();
  }
}

// shuffle the cards in the deck
void Deck::shuffle(){
  srand(time(0));
  for(int i = 0; i < 1000; i++){
    // Generate a random index number
    int x = rand() % 52;
    int y = rand() % 52;

    // Swap the cards with two randomly generated index
    Card temp = deck[x];
    deck[x] = deck[y];
    deck[y] = temp;
  }
}

// Return the number of cards left in the deck
int Deck::cardsLeft(){
  int left = 52 - topCard;
  return left;
}

// show all the cards in the deck: 13 columns and 4 rows
void Deck::showDeck(){
  for(int i = 0; i < 52; i++){
    deck[i].showCard();
    cout << " ";
  }
  cout << endl;
}