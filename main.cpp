#include <iostream>
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
void createRandomDeck(Board&);

int main(int argc, char * arv[]){
    srand(time(0));
    int turn = 1;
    
    // Set up Player board
    Board pb;
    // Create player deck and draw initial hand here:
	createRandomDeck(pb);
	pb.draw(1);
	cout << "Made it past player board setup" << endl;
    // Set up opponent board
    Board ob;
    // Create opponent deck and draw initial hand here:
	createRandomDeck(ob);
	ob.draw(1);
	cout << "Made it past opponent board setup" << endl;
    
    while(pb.getHP() > 0 && ob.getHP() > 0){
        // Take turns here:

		pb.setMaxMana(turn);
		pb.setMana(turn);
		ob.setMaxMana(turn);
		ob.setMana(turn);

		cout << "Made it into while loop" << endl;
		//getOpponentAction(ob, pb);
		getOpponentAction(pb, ob);

		cout << "End of turn #" + turn << endl;
        turn++;
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
			cout << "Made it here #2" << endl;
        }
		cout << "Made it here #3" << endl;
        renderBoard(playerBoard, opponentBoard);
    }
	cout << "Made it out of card search" << endl;
   
    // Attack with all creatures not exhausted
    for(int i = 0; i < opponentBoard.getFieldSize(); i++){
        if(!opponentBoard.getCardOnField(i)->isExhausted()){
            // get target for attack
            // look through all cards on player's board. If the card is capable of killing one of those, it will chose the first one as its target
            int targetIndex = -1;
            for(int j = 0; j < playerBoard.getFieldSize(); j++){
                if(opponentBoard.getCardOnField(i)->getAttack() > opponentBoard.getCardOnField(j)->getDefense()){
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
        }
                
    }
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
	

	return;
}

























