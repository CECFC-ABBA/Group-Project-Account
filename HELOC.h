#pragma once
/*HELOC.h
 * ABBA group memeber(s): Brendan McCleery, Anela Gallegos
 * 27 February 2020
 *	Purpose:
 * This is the HELOC class Inherrited from Account.
 * This will keep track of home equity, the loan(and interest rate), and the fee being payed.
 * (No fee, Charges, Interest)
 *	4 March 2020
 * Messed with removing and adding "variables."
 *
 *
 */

#include "Account.h"

 /*  A HELOC is a form of loan that works more like a credit card. You are enabled to pull money from the equity of your home to be
  * enabled to spend it. It'll have to be payed off in a monthly amounts based off of interest. Over the time span of a few years dependant on the loan.
  *
  */

  //Equity, credit, interest, time till payed off at minimum pay. 

	typedef class HELOC final : public Account {
	double fee = 0;
	double intr1 = 0, intr2 = 0;

	private:
		double credit = 0;
		double equity = 0;
		double loan = 0;
		double years = 0;
		double months = 0;

	public:
		//HELOC();
		//~HELOC();
		double getCredit() const {
			return credit;

		}

		double getEquity() const {
			return equity;

		}

		double getLoan() const {
			return loan;

		}

		double getYears() const {
			return years;

		}

		void setEquity(double);
		void setLoan(double);
		string fixDouble(string);
		void setYears(double);
		void setCredit(double);
		string fixDouble(string);
		string Transaction(double) final;

} HELOC;
