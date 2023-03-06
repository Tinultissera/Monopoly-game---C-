#include <iostream>
#include <ctime>
#include "Game.h"
#include "Bank.h"
#include "MoneyAction.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace std;
void welcomeMessage();
int dice();
int readSeed();

int main() {
    //welcome message
    welcomeMessage();

    //setting up the game
    int numOfPlayers = 4;
    Game* game = new Game();
    game->createPlayers(numOfPlayers);
    game->readFiles("monopoly.txt");
    Bank* bank = new Bank(10000);
    MoneyAction moneyAction;

    //begin game
    int diceRoll;
    int rounds = 20;
    srand(readSeed());

    for (int x = 0; x < rounds; x++)
    {
        for (int i = 0; i < numOfPlayers; i++) {
            if (game->isPlayerAlive(i) == true)
            {
                int playerCount = i;
                cout << endl << "Next player " << playerCount + 1 << endl;
                //rolling the die and moving the player
                //seed file read
                diceRoll = dice();

                cout << game->getPlayerName(i) << "(" << game->getGamePiece(i) << ") -> Rolls : " << diceRoll << endl;
                int pastLocation = game->getPlayerLocation(i);
                game->move(i, diceRoll);
                int currentLocation = game->getPlayerLocation(i);
                int currentOwnership = game->getSpaceOwnership(currentLocation);
                cout << game->getPlayerName(i) << "(" << game->getGamePiece(i) << ") -> lands on : " << game->getSquareName(currentLocation) << endl;

                //if pass go collect  £200
                if (pastLocation > currentLocation) {
                    moneyAction.takeFromBank(game->getPlayer(i), bank, 200);
                    cout << "*** You Passed GO! Collect  $200!***" << endl;
                }

                if (game->getSquareType(currentLocation) == 1) {//only properties
                    //pay rent
                    if (game->getSpaceOwnership(currentLocation) >= 0 && game->getMortgage(currentLocation) == false) { //property is already owned
                        if (game->getPlayerName(i) != game->getPlayerName(game->getSpaceOwnership(currentLocation)) && game->isPlayerAlive(game->getSpaceOwnership(currentLocation)) == true) { //check if the player is in another players property
                            //check location rent
                            //pay rent to owner
                            if (game->getPlayerMoney(i) <= 0) { // check is payer have enough money
                                cout << "You don't have enough money to pay the rent!!!!!!!!!!!!" << endl;
                            }
                            if (game->checkIfOwnAllColors(game->getColor(currentLocation), game->getSpaceOwnership(currentLocation))) { // if owner have bought all same color property rent gets double
                                moneyAction.payRent(game->getPlayer(i), game->getPlayer(currentOwnership), (game->getSpacePropertyRent(currentLocation) * 2));
                                cout << game->getPlayerName(i) << " Pay double rent $" << (game->getSpacePropertyRent(currentLocation) * 2) << " to " << game->getPlayerName(currentOwnership) << "-> because owner owns the whole property!!" << endl;
                            }
                            else { //pay normal rent;
                                moneyAction.payRent(game->getPlayer(i), game->getPlayer(currentOwnership), game->getSpacePropertyRent(currentLocation));
                                cout << game->getPlayerName(i) << " Pay rent $" << game->getSpacePropertyRent(currentLocation) << " to " << game->getPlayerName(currentOwnership) << endl;
                            }

                        }
                    }
                    //buy property
                    //check if property is taken or not
                    if (game->getSpaceOwnership(currentLocation) < 0 && game->getPlayerMoney(i) > 0) { // if less than 0 then property is not owned

                    //check is player has enough money to purchase property
                        if (game->getPlayerMoney(i) > 0) {
                            //purchase property
                            moneyAction.giveToBank(game->getPlayer(i), bank, game->getSpacePropertyCost(currentLocation));
                            game->setSpaceOwnership(currentLocation, i);
                            cout << game->getPlayerName(i) << " purchase property " << game->getSquareName(currentLocation) << " For : $" << game->getSpacePropertyCost(currentLocation) << endl;
                        }
                        else
                        {
                            cout << "You don't have enough money to purchase this property!!!!!!!!!!!!" << endl;
                        }

                    }


                }
                else {
                    if (game->getSquareType(currentLocation) == 6) {// if player land on jail square
                        cout << game->getPlayerName(i) << " is just visiting" << endl;
                    }
                    if (game->getSquareType(currentLocation) == 7) {//if player land on go to jail square
                        cout << game->getPlayerName(i) << " GOes to Jail and pay $50" << endl;
                        game->setPlayerLocation(game->getPlayer(i), game->getLocation(6));
                        moneyAction.takeFromPlayer(game->getPlayer(i), 50);
                    }
                    if (game->getSquareType(currentLocation) == 8) {//if player and on free park square
                        cout << game->getPlayerName(i) << " is resting" << endl;
                    }
                    if (game->getSquareType(currentLocation) == 3) {//if player lands on station square
                        if (game->getSpaceOwnership(currentLocation) < 0) {//check if station square is taken
                            if (game->getPlayerMoney(i) - game->getSpacePropertyCost(currentLocation) <= 0) {//check if player have enough money to buy station
                                cout << "You don't have enough money to purchase this property!!!!!!!!!!!!" << endl;
                            }
                            moneyAction.giveToBank(game->getPlayer(i), bank, game->getSpacePropertyCost(currentLocation));//pay station
                            game->setSpaceOwnership(currentLocation, i);//get station
                            cout << game->getPlayerName(i) << " puchase property " << game->getSquareName(currentLocation) << " For : " << game->getSpacePropertyCost(currentLocation) << endl;
                        }
                        else if (game->getSpaceOwnership(currentLocation) >= 0) { //property is already owned
                            if (game->getPlayerName(i) != game->getPlayerName(game->getSpaceOwnership(currentLocation))) { //check if the player is in another players STATION
                                if (game->getPlayerMoney(i) <= 0) {//check if player have enough money
                                    cout << "You don't have enough money to pay for the ticket!!!!!!!!!!!!" << endl;
                                }
                                //pay ticket
                                moneyAction.takeFromPlayer(game->getPlayer(i), game->getSpaceStationTicket(currentLocation));
                                cout << game->getPlayerName(i) << " Pay ticket $" << game->getSpaceStationTicket(currentLocation) << endl;
                            }
                        }
                    }
                    if (game->getSquareType(currentLocation) == 4) { //if player lands on bonus
                        //player rolls dice and occurding to number option player gain money
                        diceRoll = dice();
                        moneyAction.giveToPlayer(game->getPlayer(i), game->getBonusAmount(diceRoll));
                        cout << game->getBonusType(diceRoll) << endl;
                    }
                    if (game->getSquareType(currentLocation) == 5) {//if player lands on penalty
                        //player rolls dice and occurding to number option player lose money
                        diceRoll = dice();
                        moneyAction.takeFromPlayer(game->getPlayer(i), game->getPenaltyAmount(diceRoll));
                        cout << game->getPenaltyType(diceRoll) << endl;
                    }
                }
                cout << game->getPlayerName(i) << " has $" << game->getPlayerMoney(i) << " money left" << endl;

                //morgage properly if money lower than 0
                if (game->getPlayerMoney(i) < 0) {
                    game->mortgageProperties(i);
                    cout << game->getPlayerName(i) << " has $" << game->getPlayerMoney(i) << " money left after mogaging" << endl;
                }

                //pay back morgage if money is greater than property morgaged
                game->payBackMortage(i);

            }
        }
        cout << endl << "??????????Money left after each round????????????" << endl;
        for (int j = 0; j < numOfPlayers; j++) {
            cout << game->getPlayerName(j) << "(" << game->getGamePiece(j) << ") -> has :  $" << game->getPlayerMoney(j) << endl;
        }
    }


    cout << endl;
    for (int j = 0; j < numOfPlayers; j++) {
        if (game->isPlayerAlive(j) == false) {
            cout << game->getPlayerName(j) << " lost" << endl;
        }
        else {
            cout << game->getPlayerName(j) << " won" << endl;
        }
        cout << game->getPlayerName(j) << "(" << game->getGamePiece(j) << ") -> has :  $" << game->getPlayerMoney(j) << endl;
    }

    //destructors
    delete bank;
    delete game;
    _CrtDumpMemoryLeaks();
    return 0;
}

//afte you go 
void welcomeMessage() {
    cout << "Welcome to Monopol-ish\n";
}

int dice() {

    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
    //srand(4);

}

int readSeed()
{
    ifstream infile;
    infile.open("seed.txt");
    int seed;
    if (!infile.good())
    {
        cout << "File is not open";
    }
    else
    {
        while (infile >> seed)
        {
            return seed;
        }
    }
}