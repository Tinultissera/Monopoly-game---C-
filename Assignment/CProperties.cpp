#include "CProperties.h"
CProterties::CProterties(int type, string name, float cost, float rent, int colour) : CSquare(type , name) {
	this->cost = cost;
	this->rent = rent;
	this->colour = colour;
}

//getters
float CProterties::getCost() {
	return cost;
}
float CProterties::getRent() {
	return rent;
}
int CProterties::getColour() {
	return colour;
}