/*Anela Gallegos
Savings Class Implementations
2/28/20*/
#include "Savings.h"
#include <iostream>
#include <string>

Savings::Savings() {
	bal = 5000;
	months = 18;
	interest = 1.75;
	maxWithdraw = 3;
}

/*Savings::~Savings() {
	bal = 0;
	months = 0;
	interest = 0;
	maxWithdraw = 3;
}*/
void Savings::setBal(double num) {
	bal = num;
}

void Savings::Interest() {
	double add = bal * interest;
	bal += add;
}

string Savings::fixDouble(string doubl) {
	int index = static_cast<int>(doubl.length() - 1);
	for (int i = 0; i < static_cast<int>(doubl.length()); i++) {
		if (doubl[static_cast<int>(doubl.length() - 1) - i] == '0') {
			index--;
		}
		else {
			break;
		}
	}
	doubl = doubl.substr(0, index + 1);
	return doubl;
}

string Savings::Transaction(double amt) {
	double withdrawl = 0;
	bool con = false;
	char e = 'a';
	int choice = 0, w = 0, fee = 75;
	Interest();
	if (amt < 0) choice = 1;
	if (amt > 0) choice = 2;
	switch (choice) {
	case 1:
		withdrawl = amt / -1;
		bal -= withdrawl;
		if (w > 3) {
			bal -= fee;
		}
		if (withdrawl > 0) w++;
		break;
	case 2:
		bal += amt;
		break;
	default:
		break;
	}
	string trans = to_string(bal);
	fixDouble(trans);
	return trans;
}
//Anela
