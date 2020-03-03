/*Anela Gallegos
Savings Class Implementations
2/28/20*/
#include "Savings.h"
#include <string>

Savings::Savings() {
	bal = getBal();
	months = 18; //temp
	interest = getIntr();
	maxWithdraw = 5; //temp val
}

Savings::~Savings() {

}

void Savings::Print() {
	int years = 0;
	for (int i = 0; i <= months; i++) {
		if (i == 12) years++;
	}
	cout << "The current balance of " << accountname << " is: " << bal << endl;
	cout << accountname << " has been active for " << years << " years and " << months << " months." << endl;
	cout << "Interest Rate: " << interest << "%\n";
}

string Savings::Transaction(double amt) {
	double withdrawl;
	bool con = false;
	char e;
	//assuming transaction is only called on if withdrawl is being made
	do {
		cout << "How much would you like to withdraw? ";
		cin >> withdrawl;
		if (withdrawl > bal) cout << "Insuffient funds. Enter another value or E to exit." << endl;
		if (!e == 'E' || !e == 'e') con = true;
	} while (con == true);
	bal -= withdrawl;
	string trans = to_string(bal);
}
//Anela
