#pragma once
class Bank {
private:
	int moneyAmount;
public:
	//constructors
	Bank(int bankMoney);
	~Bank();
	//getters
	int getAmount();
	//other methods
	void giveMoney(int amount);
	void takeMoney(int amount);
};

