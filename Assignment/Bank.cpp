#include "Bank.h"
Bank::~Bank()
{
	
}

Bank::Bank(int bankMoney) {
	moneyAmount = bankMoney;
}
//getters
int Bank::getAmount() {
	return moneyAmount;
}
//other methods
void Bank::giveMoney(int amount) {
	moneyAmount = moneyAmount + amount;
}
void Bank::takeMoney(int amount) {
	moneyAmount = moneyAmount - amount;
}
