#include <iostream>
#include <string>
#include "Deck.h"
#include "Card.h"
using namespace std;


// Default Constructor
Card::Card(){
  rank = '0';
  suit = '0'; 
}

// Overloaded Constructor
Card::Card(char r, char s){
  rank = r;
  suit = s;
}

// Setting an existing blank card to a particular value
void Card::setCard(char r, char s){
  rank = r;
  suit = s;
}

// Return the point value of the card
int Card::getValue(){
  if(rank == 'A'){
    return 1;
  }
  else if(rank == '2'){
    return 2;
  }
  else if(rank == '3'){
    return 3;
  }
  else if(rank == '4'){
    return 4;
  }
  else if(rank == '5'){
    return 5;
  }
  else if(rank == '6'){
    return 6;
  }
  else if(rank == '7'){
    return 7;
  }
  else if(rank == '8'){
    return 8;
  }
  else if(rank == '9'){
    return 9;
  }
  else if(rank == 'T' || rank == 'J' || rank == 'Q' || rank == 'K'){
    return 10;
  }
  else{
    return 0;
  }
}

// Display the card using 2 fields
void Card::showCard(){
  if(rank == 'T'){
    cout << "10" << suit << " ";
  }
  else{
    cout << rank << suit << " ";
  }
}



