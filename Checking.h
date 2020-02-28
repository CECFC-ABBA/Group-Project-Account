#pragma once
#include "Account.h"
typedef class Checking final : public Account {
	double intr = 0;
	double fee = 0;
public:
	Checking();
	~Checking();
	string Transaction(double) final;
} Checking;
//Brennan
