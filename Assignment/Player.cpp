#include "Player.h"
//constructor
Player::Player() {
	moneyAmount = 1500;
	alive = true;
}
Player::~Player()
{
	
}

//setter
void Player::setPlayerName(string inputName) {
	playerName = inputName;
}

void Player::setLocation(int location) {
	this->location = location;
}

void Player::setMoneyAmount(int money) {
	moneyAmount = money;
}

void Player::setGamePiece(string inputPiece) {
	gamePiece = inputPiece;
}

void Player::setIsAlive(bool playerAlive) {
	alive = playerAlive;
}

//getter
string Player::getPlayerName() {
	return playerName;
}

int Player::getLocation() {
	if (location >= 26) {
		location = location - 26;
	}
	return location;
}

int Player::getMoneyAmount() {
	return moneyAmount;
}

string Player::getGamePiece() {
	return gamePiece;
}

bool Player::isAlive() {
	return alive;
}
//Other functions
void Player::movePlayer(int amount) {
	location = location + amount;
}

void Player::giveMoney(int amount) {
	moneyAmount = moneyAmount + amount;
}
void Player::takeMoney(int amount) {
	moneyAmount = moneyAmount - amount;
}