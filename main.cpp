#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>

#include "card.h"
#include "board.h"

#include "direRabbit.h"
#include "dragon.h"
#include "evilEye.h"
#include "goblin.h"
#include "golem.h"
#include "hobgoblin.h"
#include "magicSword.h"
#include "wargWolf.h"
#include "wizard.h"
#include "wraith.h"

const int INITIAL_DECK_SIZE = 20;

using namespace std;

void getOpponentAction(Board&, Board&);
void renderBoard(Board&, Board&);
void getPlayerAction(Board&, Board&, int);
int getMenuChoice(Board&, int);
int getHandChoice(Board&);
int getFieldChoice(Board&);
int getOpponentFieldTarget(Card*, Board&);
void createRandomDeck(Board&);

int main(int argc, char * arv[]){
    srand(time(0));
    int turn = 1;
    
    // Set up Player board
    Board pb;
    // Create player deck and draw initial hand here:
	createRandomDeck(pb);
	pb.draw(5);
    // Set up opponent board
    Board ob;
    // Create opponent deck and draw initial hand here:
	createRandomDeck(ob);
	ob.draw(5);
	//if 0 player goes first, if 1 CPU goes first
    int coinFlip = rand() % 2;
	if(coinFlip == 0){
		cout << "Heads! Player goes first." << endl;
	} else {
		cout << "Tails! CPU goes first. " << endl;
	}
    while(pb.getHP() > 0 && ob.getHP() > 0){
        // Take turns here:

		pb.setMaxMana(turn);
		pb.setMana(turn);
		ob.setMaxMana(turn);
		ob.setMana(turn);

		if(coinFlip == 0){
			getPlayerAction(pb, ob, turn);
			if(pb.getHP() <= 0 || ob.getHP() <= 0){
				break;
			}
			getOpponentAction(pb, ob);
		} else {
			getOpponentAction(pb, ob);
			if(pb.getHP() <= 0 || ob.getHP() <= 0){
				break;
			}
			getPlayerAction(pb, ob, turn);
		}

		pb.unExhaustField();
		ob.unExhaustField();

		pb.draw(1);
		ob.draw(1);

		system("sleep 1");
        turn++;
    }
    
    if(pb.getHP() > 0){
		cout << "Player wins!" << endl;
	} else {
		cout << "CPU wins!" << endl;
	}

    return 0;
}

void renderBoard(Board & pb, Board & ob){
    // Render opponent field
    ob.renderField();
    cout << endl;
    // Render player field
    pb.renderField();
    pb.renderHand();
    
    pb.renderMana();
    cout << "HP: " << pb.getHP() << " Opponent's HP: " << ob.getHP() << endl;
    
    //system("tput clear");
}

void getOpponentAction(Board & playerBoard, Board & opponentBoard){
    // Go through hand and play cards that the opponent can afford to play
    for(int i = 0; i < opponentBoard.getHandSize(); i++){

        if(opponentBoard.getCardInHand(i)->getManaCost() <= opponentBoard.getMana()){
            opponentBoard.playCardFromHand(/*opponentBoard,*/ i);
        }
        renderBoard(playerBoard, opponentBoard);
    }
	//cout << "Made it out of card search" << endl;
   
    // Attack with all creatures not exhausted
    for(int i = 0; i < opponentBoard.getFieldSize(); i++){
        if(!opponentBoard.getCardOnField(i)->isExhausted()){
            // get target for attack
            // look through all cards on player's board. If the card is capable of killing one of those, it will chose the first one as its target
            int targetIndex = -1;
            for(int j = 0; j < playerBoard.getFieldSize(); j++){
                if(opponentBoard.getCardOnField(i)->getAttack() > playerBoard.getCardOnField(j)->getDefense()){
                    targetIndex = j;
                    break;
                }
            }
            if(targetIndex != -1){
                // destory creature
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " destoryed your " << playerBoard.getCardOnField(targetIndex)->getName() << "!" << endl;
                playerBoard.discardCardFromField(targetIndex);
                renderBoard(playerBoard, opponentBoard);
            } else {
                // opponent's creature attacks player directly
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " attacks you directly for " << opponentBoard.getCardOnField(i)->getAttack() << " damage!" << endl;
                playerBoard.setHP(playerBoard.getHP() - opponentBoard.getCardOnField(i)->getAttack());
            }
			opponentBoard.getCardOnField(i)->setExhausted();
        }
                
    }
	system("sleep 2");
}

void getPlayerAction(Board& playerBoard, Board& opponentBoard, int turnNumber){

	int option;
	int handChoice;
	int attackChoice;
	int targetIndex;
	bool turnNotOver = true;

	while(turnNotOver){

		renderBoard(playerBoard, opponentBoard);
		option = getMenuChoice(playerBoard, turnNumber);

		switch(option){

			case 0:
				// Play Card from Hand
				handChoice = getHandChoice(playerBoard);
				if(handChoice == -1){
					break;
				} else {
					playerBoard.playCardFromHand(handChoice);
				}
				break;

			case 1:
				// Attack with Creature
				attackChoice = getFieldChoice(playerBoard);
				if(attackChoice == -1){
					break;
				} else {
					// get target for attack
					// look through all cards on player's board. If the card is capable of killing one of those, it will chose the first one as its target
					targetIndex = getOpponentFieldTarget(playerBoard.getCardOnField(attackChoice), opponentBoard);
					if(targetIndex == -1){
						break;
					} 
					if(targetIndex != -5){
						// destory creature
						cout << "Your " << playerBoard.getCardOnField(attackChoice)->getName() << " destoryed your opponent's " << opponentBoard.getCardOnField(targetIndex)->getName() << "!" << endl;
						opponentBoard.discardCardFromField(targetIndex);
//						renderBoard(playerBoard, opponentBoard);
					} else {
						// player's creature attacks opponent directly
						cout << "Your " << playerBoard.getCardOnField(attackChoice)->getName() << " attacks your opponent directly for " << playerBoard.getCardOnField(attackChoice)->getAttack() << " damage!" << endl;
						opponentBoard.setHP(opponentBoard.getHP() - playerBoard.getCardOnField(attackChoice)->getAttack());
//						renderBoard(playerBoard, opponentBoard);
					}
					playerBoard.getCardOnField(attackChoice)->setExhausted();
				}
				break;

			case 2:
				// End Turn
				turnNotOver = false;
				break;

			default:
				break;

		}
	}
	

	return;
}

int getMenuChoice(Board& playerBoard, int turnNumber){

	int playerChoice;

	while(true){

		cout << "Turn Number: " << turnNumber << endl;
		cout << "What would you like to do?" << endl;

		if((playerBoard.getHandSize() > 0) && (playerBoard.getMana() > 0)){

			cout << "0: Play Card from Hand" << endl;

		}

		if((playerBoard.getFieldSize() > 0) && (turnNumber != 1)){

			cout << "1: Attack with Creature" << endl;

		}

		cout << "2: End Turn" << endl;

		cin >> playerChoice;

		if(playerChoice == 0 || playerChoice == 1 || playerChoice == 2){

			break;

		} else {

			cout << "Error! Please select a valid option" << endl;

		}

	}

	return playerChoice;
}

int getHandChoice(Board& playerBoard){

	string userInput;
	const string MENU_SENTINEL = "b";
	int playerChoice;
	Card* targetCard;

	while(true){

		cout << "Please select a card to play:" << endl;
		cout << "Card #|----Name----| Mana Cost | Attack | Defense |" << endl;

		for(int i = 0; i < playerBoard.getHandSize(); i++){

			targetCard = playerBoard.getCardInHand(i);

			cout << left << setw(6) << setfill('.') << i + 1;
			cout << setw(1) << "|" << setfill(' ') << setw(12) << targetCard->getName();
			cout << right << setw(1) << "|" << setw(10) << targetCard->getManaCost();
			cout << setw(1) << " |" << setw(7) << targetCard->getAttack();
			cout << setw(1) << " |" << setw(8) << targetCard->getDefense();
			cout << setw(1) << " |" << endl;

		}
		cout << "(To return to the main menu, type b)" << endl;

		cin >> userInput;

		if(userInput == MENU_SENTINEL){

			return -1;

		} 

		playerChoice = stoi(userInput);

		if((playerBoard.getCardInHand(playerChoice - 1) != NULL) && (playerBoard.getCardInHand(playerChoice - 1)->getManaCost() <= playerBoard.getMana())){

			break;

		} else {

			cout << "Error! Please select a valid option" << endl;

		}

	}

	return playerChoice - 1;
}

int getFieldChoice(Board& playerBoard){

	string userInput;
	const string MENU_SENTINEL = "b";
	int playerChoice;
	Card* targetCard;

	while(true){

		cout << "Please select a card to attack with:" << endl;
		cout << "Card #|----Name----| Attack | Defense | Exhausted |" << endl;

		for(int i = 0; i < playerBoard.getFieldSize(); i++){

			targetCard = playerBoard.getCardOnField(i);

			cout << left << setw(6) << setfill('.') << i + 1;
			cout << setw(1) << "|" << setfill(' ') << setw(12) << targetCard->getName();
			cout << right << setw(1) << "|" << setw(7) << targetCard->getAttack();
			cout << setw(1) << " |" << setw(8) << targetCard->getDefense();
			cout << setw(1) << " |" << setw(10);
			if(targetCard->isExhausted()){

				cout << "Yes";

			} else {

				cout << "No";

			}
			cout << setw(1) << " |" << endl;

		}
		cout << "(To return to the main menu, type b)" << endl;

		cin >> userInput;

		if(userInput == MENU_SENTINEL){

			return -1;

		} 

		playerChoice = stoi(userInput);

		if(playerBoard.getCardOnField(playerChoice - 1) != NULL){

			if (playerBoard.getCardOnField(playerChoice - 1)->isExhausted()){

				cout << "Error! Please select a card that is not currently exhausted" << endl;

			} else {

				break;

			}

		} else {

			cout << "Error! Please select a valid option" << endl;

		}

	}

	return playerChoice - 1;
}

int getOpponentFieldTarget(Card* playerCard, Board& opponentBoard){

	string userInput;
	const string MENU_SENTINEL = "b";
	const string DIRECT_ATTACK_SENTINEL = "z";
	int targetChoice;
	Card* targetCard;

	while(true){

		cout << "Please select a card to attack:" << endl;
		cout << "Card #|----Name----| Attack | Defense |" << endl;

		for(int i = 0; i < opponentBoard.getFieldSize(); i++){

			targetCard = opponentBoard.getCardOnField(i);

			cout << left << setw(6) << setfill('.') << i + 1;
			cout << setw(1) << "|" << setfill(' ') << setw(12) << targetCard->getName();
			cout << right << setw(1) << "|" << setw(7) << targetCard->getAttack();
			cout << setw(1) << " |" << setw(8) << targetCard->getDefense();
			cout << setw(1) << " |" << endl;

		}
		cout << "To attack your opponent directly, press z" << endl;
		cout << "(To return to the main menu, type b)" << endl;

		cin >> userInput;

		if(userInput == MENU_SENTINEL){

			return -1;

		}

		if(userInput == DIRECT_ATTACK_SENTINEL){

			return -5;

		} 

		targetChoice = stoi(userInput);

		if(opponentBoard.getCardOnField(targetChoice - 1) != NULL){

			if(playerCard->getAttack() > opponentBoard.getCardOnField(targetChoice - 1)->getDefense()){

				break;

			} else {

				cout << "Error! The card you previously selected is not strong enough to defeat this card" << endl;

			}

		} else {

			cout << "Error! Please select a valid option" << endl;

		}

	}

	return targetChoice - 1;
}

void createRandomDeck(Board& targetBoard){

	int cardNum;
	Card* newCard;

	for(int i = 0; i < INITIAL_DECK_SIZE; i++){

		cardNum = rand() % 10 + 1;

		switch(cardNum){

			case 1:
				// DireRabbit
				newCard = new DireRabbit();
				break;

			case 2:
				// Dragon
				newCard = new Dragon();
				break;

			case 3:
				// EvilEye
				newCard = new EvilEye();
				break;

			case 4:
				// Goblin
				newCard = new Goblin();
				break;

			case 5:
				// Golem
				newCard = new Golem();
				break;

			case 6:
				// Hobgoblin
				newCard = new Hobgoblin();
				break;

			case 7:
				// MagicSword
				newCard = new MagicSword();
				break;

			case 8:
				// WargWolf
				newCard = new WargWolf();
				break;

			case 9:
				// Wizard
				newCard = new Wizard();
				break;

			case 10:
				// Wraith
				newCard = new Wraith();
				break;

			default:
				// Goblin
				newCard = new Goblin();
				break;

		}
		targetBoard.addToDeckList(newCard);
	}
	targetBoard.shuffleDeck();
	
	return;
}
