#include "Checking.h"
#include "Account.h"
#include <iostream>

/*Constructor for Checking*/
Checking::Checking(intrest, feeCost) {
	intrest = intr;
	feeCost = fee;
};

/*Destructor for Checking*/
Checking::~Checking() {
	delete []intrest;
	delete[]feeCost;
}

/*Code foe determining if the account has the money to handle a fee and reducing the balance if so*/
string Checking::Transaction(double amt) {
	amt = bal;
	double overdraft;
	string checkingOutput
	if (feeCost > amt) {
		overdraft = bal - feeCost
		amt = 0;
		checkingOutput = "There is not enougn money in your account. An overdraft will occur.";
	}
	else {
		amt = amt - feeCost;
		overdraft = 0;
		checkingOutput = "Your account has a sufficent balance.";
	}
	return checkingOutput;
}
