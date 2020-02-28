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
	if (feeCost > bal) {
		std::cout << "There is not enougn money in your account" << endl;
	}
	else {
		std::cout << "Your account has a sufficent balance" << endl;
		bal = bal - feeCost;
	}
}
