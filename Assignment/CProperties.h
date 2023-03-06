#pragma once
#include"CSquare.h"
#include<iostream>

//class CSquare;

using namespace std;

class CProterties : public CSquare {
private:
	float cost;
	float rent;
	int colour;
public:
	//constructor
	CProterties(int type, string name, float cost, float rent, int colour);

	//getters
	float getCost();
	float getRent();
	int getColour();
};

