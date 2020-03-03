#pragma once
#include "Account.h"
typedef class Checking final : public Account {/*Typedef is being ignored by the compiler*/
	double intr, fee, bal, overDraft;
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
