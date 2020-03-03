#include "Checking.h"
#include "Account.h"
#include <string>

/*Constructor for Checking*/
Checking::Checking(intrest, feeCost) {
	double intr1 = intrest;
	double fee1 = feeCost;
	double bal1 = balance;
};

/*Destructor for Checking*/
Checking::~Checking() {
	delete[]intrest;
	delete[]feeCost;
	delete[]balance;
}

/*Code for determining if the account has the money to handle a fee and reducing the balance if so*/
string Checking::Transaction(double amt) {
	double amt = balance;
	double overdraft, excess, overdraftCost = 35.00;
	string checkingOutput;
	if (fee > amt) {
		excess = bal1 - fee;
		amt = 0;
		checkingOutput = "There is not enougn money in your account. An overdraft will occur.";
		overdraft = excess + overdraftCost;
	}
	else {
		amt = amt - fee;
		excess = 0;
		checkingOutput = "Your account has a sufficent balance.";
	}
	return checkingOutput;
};
