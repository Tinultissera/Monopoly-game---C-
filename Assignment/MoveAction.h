#pragma once
#include<iostream>
#include "Player.h"

class MoveAction {
private:
	int amount;

public:
	//constructors
	MoveAction();

	//other functions
	void setAmount(int amountInput);
	void moveAmount(Player* player, int amountInput);
	int getAmount();
	void executeAction(Player* player1, Player* player2, int amount);
};


