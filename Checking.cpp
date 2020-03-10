#include "Checking.h"
#include "Account.h"
#include <string>

/*Constructor for Checking*/
Checking::Checking() {
	bal = 0;
	fee = 0;
};

/*Destructor for Checking*/
Checking::~Checking() {
	delete[]this;
	/*delete[]feeCost;
	delete[]balance;*/
}

void checkingOutput();

string fixDouble(string doubl) {
	int index = static_cast<int>(doubl.length() - 1);
	for (int i = 0; i < static_cast<int>(doubl.length()); i++) {
		if (doubl[static_cast<int>(doubl.length() - 1)-i] == '0') {
			index--;
		}
		else {
			break;
		}
	}
	doubl = doubl.substr(0, index + 1);
	return doubl;
}

/*Code for determining if the account has the money to handle a fee and reducing the balance if so*/
string Checking::Transaction(double amt) {
	bal+=amt;
	double overdraft, excess, overdraftCost = 35.00;
	string checkingOutput;
	if (fee < amt) {
		bal = bal - fee;
		excess = 0;
		void checkingOutput(){
			cout << "Your account has a sufficent balance. You have $" + fixDouble(to_string(bal)) + " remaining after the $" << fee << " cost." << endl;
		}
	}
	else {
		excess = bal - fee;
		amt = 0;
		overdraft = (excess - overdraftCost)*-1;
		void checkingOutput(){
			cout << "There is not enough money in your account. An overdraft will occur." << endl;
			cout << "Your account has been reduced to $0 and you owe the bank $" << overdraft << "." << endl;}
	}
	return checkingOutput;
};
