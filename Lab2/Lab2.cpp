#include "stdafx.h"
#include "iostream"
#include "Windows.h"
#include "cmath"
#include "time.h"
using namespace std;

//updates total money
int drawFromTotal(int totalMoney, int roundMoney)
{
	totalMoney = totalMoney - roundMoney;
	return totalMoney;
}
int addToTotal(int totalMoney, int roundMoney)
{
	totalMoney = totalMoney + roundMoney;
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
		else if (totalMoney + tempMoney == 1000) { //if total is 1000, game starts
			totalMoney = totalMoney + tempMoney;
			cout << "Total money is now: " << totalMoney << " \n";
		}
		else {		//more than 1000 is not accepted
			cout << "Exceeds total, try again \n";
		}
	}
	return totalMoney;
}
int roundFunds(int totalMoney) {
	int roundMoney = 0;
	cout << "Insert 1-50 to play, 0 to exit \n";
	cin >> roundMoney;	//input of amount chosen
	while ((roundMoney < 1) || roundMoney > 50 || roundMoney > totalMoney) {	//Loops as long as money value is wrong or to big
		cout << "Wrong input, please try again \n";
		cin >> roundMoney;	//input of amount chosen
	}
	return roundMoney;
}
void game(int money) {
	int gameEnder = 1, roundMoney = 0, totalMoney = money, rows = 0;
	char symbols[3][3];
	srand(time(NULL));		//Sets the random

	while (gameEnder != 0) {
		roundMoney = roundFunds(totalMoney);
		totalMoney = drawFromTotal(totalMoney, roundMoney);	//updated total
		for (int i = 0; i < 3; i++)	//loops over rows
		{
			for (int j = 0; j < 3; j++)	//loops over columns
			{
				symbols[i][j] = (char)((rand() % 3) + 65);	//randoms a number between 0-2 and then adds 65 to match numbers of A to C
			}
		}
		for (int x = 0; x < 3; x++)	//writes matrix
		{
			for (int y = 0; y < 3; y++)
			{
				cout << symbols[x][y] << " ";
			}
			cout << "\n";
		}
		if (symbols[0][0] == symbols[0][1] && symbols[0][0] == symbols[0][2]) {
			//first horisontal
			rows++;
		}
		if (symbols[1][0] == symbols[1][1] && symbols[1][0] == symbols[1][2]) {
			//2nd horizontal 
			rows++;
		}
		if (symbols[2][0] == symbols[2][1] && symbols[2][0] == symbols[2][2]) {
			//3d horizontal 
			rows++;
		}
		if (symbols[0][0] == symbols[1][0] && symbols[0][0] == symbols[2][0]) {
			//first vertical 
			rows++;
		}
		if (symbols[0][1] == symbols[1][1] && symbols[0][1] == symbols[2][1]) {
			//2nd vertical 
			rows++;
		}
		if (symbols[0][2] == symbols[1][2] && symbols[0][2] == symbols[2][2]) {
			//3e vertical 
			rows++;
		}
		if (symbols[0][0] == symbols[1][1] && symbols[0][0] == symbols[2][2]) {
			//left diagonal 
			rows++;
		}
		if (symbols[0][2] == symbols[1][1] && symbols[0][2] == symbols[2][0]) {
			//right diagonal 
			rows++;
		}
		cout << rows << " row(s)" << endl;
		if (rows < 5) {
			if (rows == 0) {
				roundMoney = 0;
				cout << "No matches, better luck next time" << endl;
			}
			else {
				roundMoney = roundMoney * pow(2, rows);	//learned that ^ does not work as well
				cout << "You won: " << roundMoney << endl;		//realized "endl" exists
			}
		}
		else if (rows > 5) {
			roundMoney = roundMoney * 128;
			cout << "Congratulation!!! You won the jackpot! You won: " << roundMoney << endl;
		}
		else if (rows == 5) {
			roundMoney = roundMoney * 16;
			cout << "You won: " << roundMoney << endl;
		}
		totalMoney = addToTotal(totalMoney, roundMoney);
		rows = 0;
		if (totalMoney > 0) {
			cout << "Total is now: " << totalMoney << "\nPress any key or 0 to end" << endl;
			cin >> gameEnder;
		}
		else {
			gameEnder = 0;
			cout << "Game over";
			Sleep(3000);
		}
	}
}
int main()
{
	int totalMoney = startingFunds();	//initial money with error handling
	game(totalMoney);	//game engine with inputed money to play with
	return 0;
}
