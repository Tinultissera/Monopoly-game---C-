#pragma once
#include <vector>
#include <iostream>
using namespace std;

class CSquare {
protected:
	int cType;
	string cName;
	int owned;
	bool mortgaged;
public:
	//CSquare();
	~CSquare();
	CSquare(int type, string name);
	//get
	string getName();
	int getType();
	int getOwnerShip();
	virtual float getCost();
	virtual float getRent();
	virtual int getColour();
	bool getMortgaged();
	//setter
	void setOwnerShip(int playerOwned);
	void setMortgaged(bool inputMortgage);
};

