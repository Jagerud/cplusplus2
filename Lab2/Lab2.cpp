#include "stdafx.h"
#include "iostream"
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
void game() {
	int gameEnder = 0, roundMoney = 0, totalMoney = 0;
	char symbols[3][3];
	char x, y;
	totalMoney == startingFunds();	//initial money with error handling

	while (gameEnder == 0) {
		cout << "Yo ";



		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

			}
		}


		totalMoney = updateMoney(totalMoney, roundMoney);	//updated total
	}
}
int main()
{
	game();
    return 0;
}



