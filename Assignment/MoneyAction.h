#pragma once
#include "player.h"
#include "Bank.h"

class MoneyAction {
public:
	//other methods
	void takeFromBank(Player* player, Bank* bank, int amount);
	void giveToBank(Player* player, Bank* bank, int amount);
	void payRent(Player* player1, Player* player2, int amount);
	void takeFromPlayer(Player* player, int amount);
	void giveToPlayer(Player* player, int amount);
};

