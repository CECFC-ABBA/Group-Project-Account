#pragma once
#include "Account.h"
typedef class Savings final : public Account {
private:
	string accountname;
	double bal, interest;
	int withdraws = 0, months, maxWithdraw;
	friend class Account;
public:
	Savings();
	~Savings();
	void Print();
	string Transaction(double) final;
} Checking;
//Anela
