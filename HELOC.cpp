/*HELOC.cpp
 * ABBA group memeber(s): Brendan McCleery, Anela Gallegos
 * 3 March 2020
 *	Purpose:
 * Everything in the HELOC class will be defined here.
 * This will keep track of home equity, the loan(and interest rate), and the fee being payed.
 * (No fee(?), Charges, Interest)
 *  The user will be enabled to see there current home equity. What kind of loan they can pull based off of that, with a random interest fee. 
 * It will display how many months is needed to pay off that loan and your current equity after pulling the loan.
 *
 */

#include "HELOC.h"
#include <string>

HELOC::HELOC() {
    double houseval = 125000, mortgage = 75000;
    months = 80;
    equity = houseval - mortgage;
    loan = equity - (equity * .2);
}

void HELOC::setLoan(double SetLoan) {
    loan = SetLoan;
}

string HELOC::fixDouble(string doubl) {
	int index = static_cast<int>(doubl.length() - 1);
	for (int i = 0; i < static_cast<int>(doubl.length()); i++) {
		if (doubl[static_cast<int>(doubl.length() - 1) - i] == '0') {
			index--;
		}
		else {
			break;
		}
	}
	doubl = doubl.substr(0, index + 1);
	return doubl;
}

string HELOC::Transaction(double amt) {
    char user, input, temp;
    double owed = loan;
    if (amt < 0) choice = 1;
    if (amt > 0) choice = 2;
    switch (choice) {
    case 1:
            owed += amt;
            loan -= amt;
            break;

    case 2:
            if (months => 120){
                owed += (loan * intr2);
            }
            else if (months < 120){
                owed += (loan * intr1);
            }
            break;
        default:
            break;

    }
    string trans = to_string(loan);
    fixDouble(trans);
    return trans;
}
