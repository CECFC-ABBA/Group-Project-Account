/*Anela Gallegos
Savings Class Implementations
2/28/20*/
#include "Savings.h"

Savings::Savings() {
	bal = Account:getBal();
	//months = ??
	interest = 1.75;
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
	cout << accountname << " has been active for " << ((years > 0) " and ")) << ((months > 0) months)) << "." << endl;
	cout << "Interest Rate: " << interest << "%\n";
}

string Savings::Transaction(double amt) {
	double withdrawl;
	char e;
	//assuming transaction is only called on if withdrawl is being made
	do {
		cout << "How much would you like to withdraw? ";
		cin >> withdrawl;
		if (withdrawl > bal) cout << "Insuffient funds. Enter another value or E to exit." << endl;
	} while (!e == 'E' || !e == 'e');
	bal -= withdrawl;
	amt = bal;
	return amt;
}
//Anela
