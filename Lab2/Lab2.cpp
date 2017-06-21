#include "stdafx.h"
#include "iostream"
using namespace std;


int updateMoney(int totalMoney, int roundMoney )
{
	totalMoney = totalMoney - roundMoney;
	return totalMoney;
}
int startingFunds() {
	int totalMoney, tempMoney = 1;
	cout << "Insert 20, 100 or 500 bills to fill up credit, max 1000kr \n";
	while (totalMoney <= 1000 && tempMoney != 0) { //TODO fix so that it does not go over 1000...
		cin >> tempMoney;	//input of amount chosen
		while (!(tempMoney == 20 || tempMoney == 100 || tempMoney == 500)) {	//Loops as long as money value is wrong
			cout << "Wrong input, please try again \n";
			cin >> tempMoney;	//input of amount chosen
		}
		totalMoney = totalMoney + tempMoney;
		cout << "Total money is now: " << totalMoney << " Press 0 to stop insert or continue \n";
		cin >> tempMoney;
	}
	return totalMoney;
}
int main()
{
	int gameEnder, roundMoney, totalMoney;
	char symbols[3][3];
	char x, y;
	totalMoney == startingFunds();	//initial money with error handling
	
	while (gameEnder == 0) {



		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

			}
		}


		totalMoney = updateMoney(totalMoney, roundMoney);	//updated total

		


	}

    return 0;
}



