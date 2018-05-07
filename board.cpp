#include "board.h"

using namespace std;

Board::Board(void){
	setHP(2000);
}

void Board::addToDeckList(Card* card){
	deck.push_back(card);
	return;
}

void Board::draw(int numCards){

	if(deck.empty()){
		cout << "No cards left in deck. HP reduced by 50\%." << endl;
		setHP(getHP() / 2);
		return;
	}

	if(!(deck.empty()) && (numCards > 0) && (numCards <= deck.size())){

		Card* temp;

		for(int i = 0; i < numCards; i++){

			temp = deck.back();
			hand.push_back(temp);
			deck.pop_back();

		}

	}
	
	return;
}

void Board::playCardFromHand(int cNum){

	if(!(hand.empty()) && (cNum >= 0) && (cNum < hand.size())){
		
		Card* temp = hand.at(cNum);
		field.push_back(temp);
		hand.erase(hand.begin() + cNum);

		setMana(getMana() - field.back()->getManaCost());

	}

	return;
}

Card* Board::getCardOnField(int cNum){

	if((cNum >= 0) && (cNum < field.size())){

		return field.at(cNum);

	} else {
		return nullptr;
	}
}

Card* Board::getCardInHand(int cNum){

	if(!hand.empty()){

		if((cNum >= 0) && (cNum < hand.size())){

			return hand.at(cNum);

		}
	}
	return nullptr;
}

int Board::getHP(void){
	return hp;
}

void Board::setHP(int hVal){
	hp = (hVal < 0)? 0 : hVal;
	return;
}

int Board::getHandSize(void){
	return hand.size();
}

int Board::getFieldSize(void){
	return field.size();
}

int Board::getMana(void){
	return mana;
}

void Board::setMana(int mVal){
	mana = (mVal < 0 || mVal > maxMana)? 0 : mVal;
	return;
}

int Board::getMaxMana(void){
	return maxMana;
}

void Board::setMaxMana(int turnNumber){
	maxMana = (turnNumber < 1)? 1 : turnNumber;
	return;
}

void Board::discardCardFromField(int cNum){
	if(!(field.empty()) && (cNum >= 0) && (cNum < field.size())){
		Card* temp = field.at(cNum);
		discard.push_back(temp);
		field.erase(field.begin() + cNum);
	}
	return;
}

void Board::unExhaustField(void){

	for(int i = 0; i < field.size(); i++){

		field[i]->unExhaust();

	}

	return;
}

void Board::shuffleDeck(void){
    Card * temp;
    int numOfShuffles = 100;
    int idx1, idx2;
    for(int i = 0; i < numOfShuffles; i++){
        idx1 = rand() % deck.size();
        idx2 = rand() % deck.size();
        temp = deck[idx1];
        deck[idx1] = deck[idx2];
        deck[idx2] = temp;
    }
}


void Board::renderMana(void){
    cout << "MANA: ";
    for(int i = 1; i <= maxMana; i++){
        if(i <= mana)
            cout << "@ ";
        else
            cout << "O ";
    }
        
    cout << endl;
}

void Board::renderHand(void){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                cout << hand[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}

void Board::renderField(void){
    if(field.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < field.size(); j++){
                cout << field[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}

void Board::populateFromFile(void){

	string filename;
	string cardName;
	ifstream save_file;
	int cardNum;
	Card* newCard;
	int lineCounter = 1;
	bool unrecognizedCardNamesError = false;
	
	deck.clear();

	// Holds card mappings for populateFromFile
	unordered_map<string, int> cardNameMappings;
	cardNameMappings["Dire Rabbit"] = 1;
	cardNameMappings["Dragon"] = 2;
	cardNameMappings["Evil Eye"] = 3;
	cardNameMappings["Goblin"] = 4;
	cardNameMappings["Golem"] = 5;
	cardNameMappings["Hobgoblin"] = 6;
	cardNameMappings["Magic Sword"] = 7;
	cardNameMappings["Warg Wolf"] = 8;
	cardNameMappings["Wizard"] = 9;
	cardNameMappings["Wraith"] = 10;

	while(true){

		cout << "Please select a filename (including .txt file extension) to load a deck from: " << endl;
		cin >> filename;

		if(!fileExists(filename)){

			cout << "Error! File not found!" << endl;

		} else {

			break;

		}

	}
	save_file.open(filename);

	while((!save_file.fail()) && (!save_file.eof()) && (lineCounter < getMaxDeckSize())){

		getline(save_file, cardName);
		auto pos = cardNameMappings.find(cardName);
		if(pos == cardNameMappings.end()){

			unrecognizedCardNamesError = true;
			break;

		}
		lineCounter++;
	}
	if(save_file.fail()){

		cout << "Error! An unknown error has occurred" << endl;
		populateFromFile();

	} else if(lineCounter < getMaxDeckSize()){

		cout << "Error! The chosen save file appears to have fewer than the required " << getMaxDeckSize() << " cards" << endl;
		populateFromFile();

	} else if(unrecognizedCardNamesError){

		cout << "Error! The chosen save file contains unrecognized card names" << endl;
		populateFromFile();

	} else {

		save_file.clear();
		save_file.seekg(0, ios::beg);
		for(int index = 0; index < getMaxDeckSize(); index++){

			getline(save_file, cardName);

			switch(cardNameMappings.at(cardName)){

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
			addToDeckList(newCard);

		}

	}
	
	return;
}

void Board::saveToFile(void){

	string filename;
	string overwriteFileChoice;
	ofstream save_file;

	while(true){

		cout << "Please select a filename (including .txt file extension) to save your current deck to: " << endl;
		cin >> filename;

		if(fileExists(filename)){

			cout << "Warning! File \"" << filename << "\" already exists and will be overwritten! Proceed? (y/n)" << endl;
			cin >> overwriteFileChoice;
			
			if(overwriteFileChoice == "y"){

				break;

			}


		} else {

			break;

		}

	}
	save_file.open(filename);

	for(int index = 0; index < deck.size(); index++){

		save_file << deck.at(index)->getName() << endl;

	}
	for(int index = 0; index < hand.size(); index++){

		save_file << hand.at(index)->getName() << endl;

	}
	for(int index = 0; index < field.size(); index++){

		save_file << field.at(index)->getName() << endl;

	}
	for(int index = 0; index < discard.size(); index++){

		save_file << discard.at(index)->getName() << endl;

	}
	save_file.close();
	
	return;
}
