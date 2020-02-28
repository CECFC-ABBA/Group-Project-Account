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
	if (feeCost > amt) {
		std::cout << "There is not enougn money in your account. An overdraft will occur." << endl;
		overdraft = bal - feeCost
		amt = 0;
	}
	else {
		std::cout << "Your account has a sufficent balance." << endl;
		amt = amt - feeCost;
		overdraft = 0;
	}
	return string;
}
