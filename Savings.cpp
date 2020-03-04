/*Anela Gallegos
Savings Class Implementations
2/28/20*/
#include "Savings.h"
#include <string>

Savings::Savings() {
	bal = getBal();
	months = getMonths();
	interest = getIntr();
	maxWithdraw = 3;
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

void Savings::Interest() {
	double add = bal * interest;
	bal += add;
	cout << "Account balance with interest is: " << bal << endl;
}

string Savings::Transaction(double amt) {
	double withdrawl = 0, tbal;
	bool con = false;
	char e = 'a';
	int choice, w = 0, fee = 75;
	Print();
	Interest();
	cout << "1. Make a withdrawl\2. Make a deposit\n3. Exit" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		do {
			cout << "How much would you like to withdraw? ";
			cin >> withdrawl;
			if (w > 3) tbal = (bal -= fee);
			if (withdrawl > bal || withdrawl > tbal) cout << "Insuffient funds. Enter another value or E to exit." << endl;
			if (!(e == 'E') || !(e == 'e')) con = true;
		} while ((con == true) || (w <= maxWithdraw));
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
		double deposit;
		cout << "What is the deposit amount? ";
		cin >> deposit;
		bal += deposit;
		cout << "After your deposit is verified, your account balance will be: $" << bal << endl;
		break;
	default:
		break;
	}
	string trans = to_string(bal);
	return trans;
}
//Anela
