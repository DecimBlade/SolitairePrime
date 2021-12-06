/**
Ellesia Truong 026588859
Program #1 - Solitaire Prime
CECS 282-Sec 04
Due Date: September 14, 2021 11:59pm
*/

#include <iostream>
#include <string>
#include "Deck.h"
#include "Card.h"
using namespace std;

void displayMenu(){
  cout << "1. New Deck\n";
  cout << "2. Display Deck\n";
  cout << "3. Shuffle Deck\n";
  cout << "4. Play Solitaire Prime\n";
  cout << "5. Exit\n";
}

bool isPrime(int x){
  // This condition checks if x is 0 or 1 because 0 and 1 do not count as prime numbers, so return false
  if(x == 0 || x == 1){
    return false;
  }

  for(int i = 2; i < x; i++){
    if(x % i == 0){
      return false;
    }
  }
  return true;
}

// main function
int main() {
  Deck deck;
  int pileSum = 0;
  int piles = 0;
  int menuInput;
  bool runGame = true;
  cout << "Welcome to Solitaire Prime!!!\n";

  while(runGame){
    displayMenu();
    cout << "Enter menu selection: ";
    cin >> menuInput;

    // Creates a new deck
    if(menuInput == 1){
      cout << "Creating a new deck.\n";
      deck.refreshDeck();
    }

    // Displays the current deck
    else if(menuInput == 2){
      cout << "Displaying the current deck.\n";
      deck.showDeck();
    }

    // Shuffles the deck
    else if(menuInput == 3){
      cout << "Shuffling the deck.\n";
      deck.shuffle();
    }

    // Plays solitaire prime
    else if(menuInput == 4){
      cout << "Playing Solitaire Prime!\n";
      cout << endl;
      int piles = 0;
      int pileSum = 0;
      int lastPile = 0;
      while(true){
        
        if(deck.cardsLeft() == 0){
          break;
        }

        Card card = deck.deal();
        int cardValue = card.getValue();
        pileSum = pileSum + cardValue;
        card.showCard();

        if(isPrime(pileSum)){
          cout <<"Prime: " << pileSum;
          cout << endl;
          piles = piles + 1;
          lastPile = pileSum;
          pileSum = 0;
          continue;
        }
        else{
          lastPile = pileSum;

        }
      }
  
      if(deck.cardsLeft() == 0 && isPrime(lastPile)){
        cout << "Winner in " << piles << " piles!\n";
      }
      
      if(deck.cardsLeft() == 0 && !isPrime(lastPile)){
        cout << endl;
        cout << "Loser\n";
      }
    }

    // Exits the game
    else if(menuInput == 5){
      cout << "Exiting Game! Thank you for playing!";
      runGame = false;
    }
  }
  return 0;
}