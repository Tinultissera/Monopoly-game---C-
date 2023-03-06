#include "Game.h"
#include<iostream>

Game::~Game()
{
    delete[] players;

    for (int i = 0; i < 26; ++i)
    {
        delete squars[i];
    }
}

// getters
string Game::getPlayerName(int playerNum) {
	return players[playerNum].getPlayerName();
}

string Game::getGamePiece(int playerNum) {
	return players[playerNum].getGamePiece();
}

int Game::getPlayerMoney(int playerNum) {
    return players[playerNum].getMoneyAmount();
}

int Game::getPlayerLocation(int playerNum) {
	return players[playerNum].getLocation();
}

string Game::getSquareName(int location) {
	return squars[location]->getName();
}

int Game::getSquareType(int location) {
    return squars[location]->getType();
}

Player* Game::getPlayer(int i) {
    return &players[i];
}

int Game::getSpaceOwnership(int locationIndex) {
    return squars[locationIndex]->getOwnerShip();
}

int Game::getSpacePropertyCost(int locationIndex) {
    return squars[locationIndex]->getCost();
}

int Game::getSpacePropertyRent(int locationIndex) {
    return squars[locationIndex]->getRent();
}

int Game::getSpaceStationTicket(int locationIndex) {
    return squars[locationIndex]->getRent();
}

int Game::getLocation(int type) {
    for (int i = 0; i < squars.size(); i++) {
        if (squars[i]->getType() == type) {
            return i;
        }
    }
}
int Game::getBonusAmount(int diceNum) { //get bonus amount 
    if (diceNum == 1) {
        return 20;
    }
    if (diceNum == 2) {
        return 50;
    }
    if (diceNum == 3) {
        return 100;
    }
    if (diceNum == 4) {
        return 150;
    }
    if (diceNum == 5) {
        return 200;
    }
    if (diceNum == 6) {
        return 300;
    }
}

string Game::getBonusType(int diceNum) { //get bonus type
    if (diceNum == 1) {
        return "Find some money. Gain $20";
    }
    if (diceNum == 2) {
        return "Win a coding competition. Gain $50";
    }
    if (diceNum == 3) {
        return "Receive a rent rebate. Gain $100";
    }
    if (diceNum == 4) {
        return "Win the lottery. Gain $150";
    }
    if (diceNum == 5) {
        return "Receive a bequest. Gain $200";
    }
    if (diceNum == 6) {
        return "It’s your birthday. Gain $300";
    }
}
int Game::getPenaltyAmount(int diceNum) {//get penalty amounts
    if (diceNum == 1) {
        return 20;
    }
    if (diceNum == 2) {
        return 50;
    }
    if (diceNum == 3) {
        return 100;
    }
    if (diceNum == 4) {
        return 150;
    }
    if (diceNum == 5) {
        return 200;
    }
    if (diceNum == 6) {
        return 300;
    }
}
string Game::getPenaltyType(int diceNum) {//get penalty type names
    if (diceNum == 1) {
        return "Buy a coffee in Starbucks. Lose $20";
    }
    if (diceNum == 2) {
        return "Pay your broadband bill. Lose $50";
    }
    if (diceNum == 3) {
        return "Visit the SU shop for food. Lose $100";
    }
    if (diceNum == 4) {
        return "Buy an assignment solution. Lose $150";
    }
    if (diceNum == 5) {
        return "Go for a romantic meal. Lose $200";
    }
    if (diceNum == 6) {
        return "Pay some university fees. Lose $300";
    }
}
bool Game::isPlayerAlive(int i) {
    return players[i].isAlive();
}

bool Game::getMortgage(int locationIndex) {
    return squars[locationIndex]->getMortgaged();
}

int Game::getColor(int locationIndex)
{
    return squars[locationIndex]->getColour();
}


//setters
void Game::setSpaceOwnership(int locationIndex, int i) {
    squars[locationIndex]->setOwnerShip(i);
    squars[locationIndex]->setMortgaged(false);
}

void Game::setPlayerLocation(Player* player, int amount) {
    player->setLocation(amount);
}

void Game::setPlayerNotAlive(int i) {
    players->setIsAlive(false);
}


//other methods
void Game::move(int numPlayer, int amountInput) {
    movement.moveAmount(&(players[numPlayer]), amountInput);
}

void Game::createPlayers(int numPlayers) {
    int totalNumPlayers = numPlayers;
    //players = new Player[numPlayers];
    
    if (totalNumPlayers == 2) {
        players[0].setPlayerName("Tom");
        players[0].setGamePiece("dog");
        players[1].setPlayerName("Jerry");
        players[1].setGamePiece("car");
    }
    else if (totalNumPlayers == 4) {
        players[0].setPlayerName("Tom");
        players[0].setGamePiece("dog");

        players[1].setPlayerName("Jerry");
        players[1].setGamePiece("car");

        players[2].setPlayerName("Micky");
        players[2].setGamePiece("shoe");

        players[3].setPlayerName("Tinul");
        players[3].setGamePiece("hat");
    }
}

void Game::readFiles(string fileName) {
    string line, word1, word2, word3, name;
    int type, colour;
    float cost, rent;
    ifstream infile;
    infile.open(fileName);
    if (!infile.good())
    {
        cout << "File is not open";
    }
    else
    {
        istringstream iss;
        vector<string> storedate;
        while (!infile.eof()) {
            getline(infile, line);
            //if (infile.eof()) {
                iss.clear();
                iss.str(line);
                while (iss.good()) {
                    if (line[0] == '1') {
                        iss >> type >> word1 >> word2 >> cost >> rent >> colour;
                        name = word1 + " " + word2;
                        break;
                    }
                    else if (line[0] == '7') {
                        iss >> type >> word1 >> word2 >> word3;
                        name = word1 + " " + word2 + " " + word3;
                        break;
                    }
                    else if (line[0] == '3') {
                        iss >> type >> word1 >> word2;
                        name = word1 + " " + word2;
                        break;
                    }
                    else if (line[0] == '8') {
                        iss >> type >> word1 >> word2;
                        name = word1 + " " + word2;
                        break;
                    }
                    else if (line[0] == '4') {
                        iss >> type >> word1;
                        name = word1;
                        break;
                    }
                    else if (line[0] == '5') {
                        iss >> type >> word1;
                        name = word1;
                        break;
                    }
                    else {
                        iss >> type >> word1;
                        name = word1;
                        break;
                    }
                }
                if (type == 1) {
                    squars.push_back(new CProterties(type, name, cost, rent, colour));
                }
                else {
                    if (type == 6) {
                        squars.push_back(new JailSquare(type, name));
                    }
                    else if (type == 7) {
                        squars.push_back(new GoToJailSquare(type, name));
                    }
                    else if (type == 8) {
                        squars.push_back(new FreeParkingSquare(type, name));
                    }
                    else if (type == 3) {
                        squars.push_back(new StationSquare(type, name));
                    }
                    else if (type == 4) {
                        squars.push_back(new BonusSquare(type, name));
                    }
                    else if (type == 5) {
                        squars.push_back(new PenaltySquare(type, name));
                    }
                    else {
                        squars.push_back(new CSquare(type, name));
                    }
                }
                word1 = " ";
                word2 = " ";
                word3 = " ";
        }
    }
}

bool Game::checkIfOwnAllColors(int color, int playernum) {
    bool found = false;
    for (int i = 0; i < squars.size(); ++i)
    {
	    if(squars[i]->getColour() == color && squars[i]->getType() == 1)
	    {
		    if(squars[i]->getOwnerShip() == playernum)
		    {
                found = true;
		    }else
		    {
                found = false;
                break;
		    }
	    }
    }
    return found;

}

void Game::mortgageProperties(int i) {
    for (int j = 0; j < squars.size(); j++) {
        if (squars[j]->getOwnerShip() == i && players[i].getMoneyAmount() < 0 && squars[j]->getMortgaged() == false) {
            players[i].giveMoney(squars[j]->getCost());
            squars[j]->setMortgaged(true);
        }
    }
    if (players[i].getMoneyAmount() <= 0)
    {
        players[i].setIsAlive(false);
        cout << players[i].getPlayerName() << " : Bankrupt, player lost!!" << endl;
    }
}

void Game::payBackMortage(int i) {
    for (int j = 0; j < squars.size(); j++) {
        if (squars[j]->getOwnerShip() == i && squars[j]->getMortgaged() == true) {
            if (players[i].getMoneyAmount() > squars[j]->getCost()) {
                players[i].takeMoney(squars[j]->getCost());
                squars[j]->setMortgaged(false);
            }
        }
    }
}