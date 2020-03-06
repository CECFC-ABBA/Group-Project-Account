/*Anela Gallegos
Savings Class Implementations
2/28/20*/
#include "Savings.h"
#include <string>

Savings::Savings() {
	bal = 5000;
	months = 18;
	interest = 1.75;
	maxWithdraw = 3;
}

Savings::~Savings() {
	//Create destructor:

}

void Savings::Print() {
	bal = getBal();
	months = getMonths();
	interest = getIntr();
	int years = months%12;
	cout << "The current balance of " << accountname << " is: " << bal << endl;
	cout << accountname << " has been active for " << years << " years and " << months << " months." << endl;
	cout << "Interest Rate: " << interest << "% \n";
}

void Savings::Interest() {
	double add = bal * interest;
	bal += add;
	cout << "Account balance with interest is: " << bal << endl;
}

string Savings::Transaction(double amt) {
	double withdrawl = 0, tbal;
	bool con = false;
	char e = 'a';
	int choice = 0, w = 0, fee = 75;
	Print();
	Interest();
	if (amt < 0) choice = 1;
	if (amt > 0) choice = 2;
	switch (choice) {
	case 1:
		do {
			withdrawl = amt / -1;
			if (w > 3) tbal = (bal -= fee);
			if (withdrawl > bal || withdrawl > tbal) {
				cout << "Insuffient funds. Enter another value." << endl;
				cin >> withdrawl;
			}
		} while (w <= maxWithdraw);
		bal -= withdrawl;
		if (w > 3) {
			bal -= fee;
			cout << "You have been charged for going over your withdrawl limit." << endl;
		}
		if (withdrawl > 0) w++;
		if (w == maxWithdraw) cout << "You cannot make any more withdrawls without an added fee." << endl;
		else if (w == 2) cout << "You may make one more free withdrawl." << endl;
		else if (w == 1) cout << "You make make two more free withdrawls." << endl;
		break;
	case 2:
		bal += amt;
		cout << "After your deposit is verified, your account balance will be: $" << bal << endl;
		break;
	default:
		break;
	}
	string trans = to_string(bal);
	return trans;
}
//Anela
