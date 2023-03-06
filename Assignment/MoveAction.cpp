#include "MoveAction.h"
MoveAction::MoveAction() {
	amount = 0;
}

void MoveAction::setAmount(int amountInput) {
	amount = amountInput;
}

void MoveAction::moveAmount(Player* player, int amountInput) {
	player->movePlayer(amountInput);
}

int MoveAction::getAmount() {
	return amount;
}

void MoveAction::executeAction(Player* player1, Player* player2, int amount) {
	//does nothing
}
