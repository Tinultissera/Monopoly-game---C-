#include "CSquare.h"

/*CSquare::CSquare() {
	copy(data.begin(), data.end(), back_inserter(obj));
}*/
CSquare::~CSquare() {

}

CSquare::CSquare(int type, string name) {
    cType = type;
    cName = name;
}

//setters
void CSquare::setOwnerShip(int playerOwned) {
    owned = playerOwned;
}

void CSquare::setMortgaged(bool inputMortgage) {
    mortgaged = inputMortgage;
}

//getters
string CSquare::getName() {
    return cName;
}
int CSquare::getType() {
    return cType;
}
float CSquare::getCost() {
    return 0;
}
float CSquare::getRent() {
    return 0;
}
int CSquare::getColour() {
    return 0;
}
int CSquare::getOwnerShip() {
    return owned;
}

bool CSquare::getMortgaged() {
    return mortgaged;
}