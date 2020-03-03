#pragma once
#include "Account.h"
typedef class Savings final : public Account {
private:
	string accountname;
	double bal, interest;
	int withdraws = 0, months, maxWithdraw;
public:
	Savings();
	~Savings();
	void Print();
	void Interest();
	string Transaction(double) final;
} Checking;
//Anela
