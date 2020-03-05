#pragma once
/*HELOC.h
 * Anela
 *
 */

#include "Account.h"

 /*  A HELOC is a form of loan that works more like a credit card. You are enabled to pull money from the equity of your home to be
  * enabled to spend it. It'll have to be payed off in a monthly amounts based off of interest.
  *
  */

typedef class HELOC final : public Account {
private:
	//Equity
	double equity, loan, fee = 0, intr;
    double months;

public:
	HELOC();
	~HELOC();
	double getEqu() const {
		//return equ;

	}

	double getLoan() const {
		return loan;

	}
    double Calculate(double);

	string Transaction(double) final;

} HELOC;
