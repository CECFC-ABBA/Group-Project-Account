#include "Checking.h"
#include "Account.h"
#include <string>

/*Constructor for Checking*/
Checking::Checking() {
	bal = 0;
};

/*Destructor for Checking*/
Checking::~Checking() {
	delete[]this;
	/*delete[]feeCost;
	delete[]balance;*/
}

/*Code for determining if the account has the money to handle a fee and reducing the balance if so*/
string Checking::Transaction(double amt) {
	bal+=amt;
	double overdraft, excess, overdraftCost = 35.00;
	string checkingOutput;
	if (fee < amt) {
		bal = bal - fee;
		excess = 0;
		checkingOutput = "Your account has a sufficent balance.";
	}
	else {
		excess = bal - fee;
		amt = 0;
		checkingOutput = "There is not enough money in your account. An overdraft will occur.";
		overdraft = excess + overdraftCost;
		cout << "You owe the bank " << overdraft << " dollars." << endl;
	}
	return checkingOutput;
};
