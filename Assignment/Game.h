#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Player.h"
#include "CSquare.h"
#include "MoveAction.h"
#include "CProperties.h"
#include "JailSquare.h"
#include "GoToJailSquare.h"
#include "FreeParkingSquare.h"
#include "StationSquare.h"
#include "BonusSquare.h"
#include "PenaltySquare.h"



class Game {
private:
	Player* players = new Player[4];
	MoveAction movement;
	vector<CSquare*> squars;
	
public:
	~Game();
	//other methods
	void readFiles(string fileName);
	void createPlayers(int numPlayers);
	void move(int numPlayer, int amountMove);
	bool checkIfOwnAllColors(int color, int playernum);
	void mortgageProperties(int i);
	void payBackMortage(int i);
	void displayHorizontal(int firstSpace, int lastSpace, int numPlayers);
	void displayVertical(int firstSpace, int lastSpace, int numPlayers);
	//getters
	string getPlayerName(int playerNum);
	string getGamePiece(int playerNum);
	int getPlayerMoney(int playerNum);
	int getPlayerLocation(int playerNum);
	string getSquareName(int location);
	int getSquareType(int location);
	Player* getPlayer(int num);
	int getSpaceOwnership(int locationIndex);
	int getSpacePropertyCost(int locationIndex);
	int getSpacePropertyRent(int locationIndex);
	int getSpaceStationTicket(int locationIndex);
	int getLocation(int type);
	int getBonusAmount(int diceNum);
	string getBonusType(int diceNum);
	int getPenaltyAmount(int diceNum);
	string getPenaltyType(int diceNum);
	bool isPlayerAlive(int i);
	bool getMortgage(int locationIndex);
	int getColor(int locationIndex);

	//setters
	void setSpaceOwnership(int locationIndex, int i);
	void setPlayerLocation(Player* player, int amount);
	void setPlayerNotAlive(int i);
};

