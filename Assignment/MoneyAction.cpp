#include "MoneyAction.h"
void MoneyAction::takeFromBank(Player* player, Bank* bank, int amount) {
	bank->takeMoney(amount);
	player->giveMoney(amount);
}
void MoneyAction::giveToBank(Player* player, Bank* bank, int amount) {
	player->takeMoney(amount);
	bank->giveMoney(amount);
}

void MoneyAction::payRent(Player* player1, Player* player2, int amount) {
	player1->takeMoney(amount);
	player2->giveMoney(amount);
}
void MoneyAction::takeFromPlayer(Player* player, int amount) {
	player->takeMoney(amount);
}
void MoneyAction::giveToPlayer(Player* player, int amount) {
	player->giveMoney(amount);
}
