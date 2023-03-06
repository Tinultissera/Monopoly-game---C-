#include "StationSquare.h"
StationSquare::StationSquare(int type, string name) : CSquare(type, name) {
	this->cost = 200;
	this->ticket = 10;
}
float StationSquare::getCost() {
	return cost;
}

float StationSquare::getRent() {
	return ticket;
}