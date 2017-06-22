#include "stdafx.h"
#include "iostream"
#include "Windows.h"
using namespace std;

//updates total money
int updateMoney(int totalMoney, int roundMoney )
{
	totalMoney = totalMoney - roundMoney;
	return totalMoney;
}
//Sets the total money for the user to play with
int startingFunds() {
	int totalMoney = 0, tempMoney = 1;
	cout << "Insert 20, 100 or 500 bills to fill up credit, max 1000kr, 0 to exit \n";
	while (totalMoney < 1000 && tempMoney != 0) {	//loops as long as less than 1000kr and user didnt press 0
		cin >> tempMoney;	//input of amount chosen
		while ((totalMoney <= 1000) && !(tempMoney == 0 || tempMoney == 20 || tempMoney == 100 || tempMoney == 500)) {	//Loops as long as money value is wrong
			cout << "Wrong input, total is " << totalMoney << ", please try again \n";
			cin >> tempMoney;	//input of amount chosen
		}
		if (totalMoney + tempMoney < 1000) {	//If total is less than 1000, can continue filling money or start
			totalMoney = totalMoney + tempMoney;
			cout << "Total money is now: " << totalMoney << " Press 0 to stop insert or continue \n";
		}
		else if(totalMoney + tempMoney == 1000){ //if total is 1000, game starts
			totalMoney = totalMoney + tempMoney;
			cout << "Total money is now: " << totalMoney << " \n";
		}
		else {		//more than 1000 is not accepted
			cout << "Exceeds total, try again \n";
		}
	}
	return totalMoney;
}
void game(int money) {
	int gameEnder = 0, roundMoney = 0, totalMoney = money;
	char symbols[3][3];
	
	while (gameEnder == 0) {
		totalMoney = updateMoney(totalMoney, roundMoney);	//updated total
		for (int i = 0; i < 3; i++)	//loops over rows
		{
			for (int j = 0; j < 3; j++)	//loops over columns
			{
				symbols[i][j] = (char)((rand() % 3) + 65);	//randoms a number between 0-2 and then adds 65 to match numbers of A to C
			}
		}
		for (int i = 0; i < 3; i++)	//writes matrix
		{
			for (int j = 0; j < 3; j++)
			{
				cout << symbols[i][j] << " "; 
			}
			cout << "\n";
		}

		
	}
}
int main()
{
	int totalMoney = startingFunds();	//initial money with error handling
	game(totalMoney);	//game engine with inputed money to play with
    return 0;
}



