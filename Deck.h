#ifndef Deck_H
#define Deck_H
#include "Card.h"

class Deck{
  private:
  int topCard;
    Card deck[52];
  public:
    Deck();
    void refreshDeck();
    Card deal();
    void shuffle();
    int cardsLeft();
    void showDeck();
};

#endif