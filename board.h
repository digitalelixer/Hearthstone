#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "card.h"

class Board{
    private:
        // The current amount of health.
        int hp;
        // The amount of mana available to spend.
        int mana;
        // The max amount of mana available per turn. Should be equal to the current turn.
        int maxMana;
    
        /* deck
         * 
         * This vector is used to hold pointers to all the cards in a player's 
         * deck. The deck should contain 20 cards at the start of the game.
         */
        vector<Card*> deck;
        
        /* hand
         *
         * This vector contains pointers to all the cards in the player's hand.
         */
        vector<Card*> hand;
        
        /* discard
         * 
         * This vector contains pointers to all the cards in the discard pile.
         */
        vector<Card*> discard;
        
        /* field
         * 
         * This vector contains pointers to all the cards on the field.
         */
        vector<Card*> field;
    
    public:
        /* Constructor for Board
         *
         * This constructor should be used to initalize a player's health 
         * to 2000 when called.
         */
        Board(void);
        
        /* addToDeckList
         *
         * This function adds a card pointer to the deck vector. Used to add
         * cards to the deck before the start of the game.
         */
        void addToDeckList(Card*);
        
        /* draw
         *
         * This function pops a Card pointer off of the deck vector and 
         * pushes it onto the hand vector. The integer passed to this 
         * function determines how many cards to draw.
         */
        void draw(int);
        
        /* playCardFromHand
         *
         * This function plays a card from the hand. The integer passed to
         * the function is the index of the card to play in the hand vector.
         * The mana cost of the card is subtracted from the player's current
         * mana count.
         */
        void playCardFromHand(int);
        
        /* getCardOnField
         *
         * Accessor function to retrieve the pointer to the card on the
         * field at the specified index.
         */
        Card* getCardOnField(int);
        
        /* getCardInHand
         *
         * Accessor function to retrieve the pointer to the card in the
         * hand at the specified index.
         */
        Card* getCardInHand(int);
        
        /* getHP
         *
         * Accessor function for HP.
         */
        int getHP(void);
        
        /* setHP
         *
         * Mutator function for HP.
         */
        void setHP(int);
        
        /* getHandSize
         *
         * Returns the current size of the hand vector.
         */
        int getHandSize(void);
        
        /* getFieldSize
         *
         * Returns the current size of the field vector.
         */
        int getFieldSize(void);
        
        /* getMana
         *
         * Returns the current amount of mana.
         */
        int getMana(void);
        
        /* setMana
         *
         * Mutator function for mana.
         */
        void setMana(int);
        
        /* discardCardFromField
         *
         * Removes a card at a specified index from the field vector and adds
         * it to the discard vector.
         */
        void discardCardFromField(int);
        
        /* unExhaustField
         *
         * Sets the exhausted value to false for all cards in the field vector.
         */
        void unExhaustField(void);
        
        /* shuffleDeck
         *
         * Scrambles the order of the values in deck vector.
         */
        void shuffleDeck(void);
        
        /* renderMana
         * 
         * Draws the current mana count.
         */
        void renderMana(void);
        
        /* renderHand
         *
         * Draws the cards in the hand vector to the console.
         */
        void renderHand(void);
        
        /* renderField
         *
         * Draws the cards in the field vector to the console.
         */
        void renderField(void);
};


#endif