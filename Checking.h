#pragma once
#include "Account.h"
class Checking final : public Account {
	double intr = 0;
	double fee = 0;
	double bal = 0;
	double overDraft;
public:
	double intrest = intr;
	double feeCost = fee;
	double balance = bal;
	Checking();
	~Checking();
	string Transaction(double) final;
	double getOverDraft() const {
		return overDraft;
	}
};
#define MAIN
//#define FANCYMAIN
