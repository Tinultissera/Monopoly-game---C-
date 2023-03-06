#pragma once
#include <iostream>

using namespace std;

class Player {
private:
	string playerName;
	string gamePiece;
	int moneyAmount;
	int location = 0;
	bool alive;
public:
	// constructor
	Player();
	~Player();
	//functions to set values
	void setPlayerName(string inputName);
	void setGamePiece(string inputPiece);
	void setIsAlive(bool playerAlive);
	void setLocation(int spaceNum);
	void setMoneyAmount(int money);

	//functions to get values
	string getPlayerName();
	string getGamePiece();
	int getMoneyAmount();
	int getLocation();
	bool isAlive();

	//other functions
	void movePlayer(int amount);
	void giveMoney(int amount);
	void takeMoney(int amount);
};

