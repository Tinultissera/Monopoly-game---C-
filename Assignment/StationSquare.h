#pragma once
#include"CSquare.h"
#include<iostream>
using namespace std;

class StationSquare : public CSquare {
private:
	float cost;
	float ticket;
public:
	StationSquare(int type, string name);
	float getCost();
	float getRent();
};

