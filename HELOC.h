#pragma once
/*HELOC.h
 * ABBA group memeber: Brendan McCleery.
 * 27 February 2020
 *	Purpose:
 * This is the Heloc class Inherrited from Account. 
 * This will keep track of home equity, the loan(and interest rate), and the fee being payed. 
 * (No fee, Charges, Interest)
 *
 */

#include "Account.h"

/*  A HELOC is a form of loan that works more like a credit card. You are enabled to pull money from the equity of your home to be 
 * enabled to spend it. It'll have to be payed off in the monthly amounts based off of interest. 
 *
 */

typedef class HELOC final : public Account {
	//Equity 
	double fee = 0;
	double intr = 0;

public:
	HELOC();
	~HELOC();
	string Transaction(double) final;

} HELOC;

