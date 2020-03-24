#pragma once
#include "Account.h"
typedef class Savings final : public Account {
private:
	string accountname;
	double bal = 0, interest = 0;
	int withdraws = 0, months = 0, maxWithdraw = 0;
public:
	Savings();
	void Interest();
		double getBal() {
		return bal;
	}
	string fixDouble(string);
	string Transaction(double) final;
} Savings;
//Anela
