#pragma once
#include "Account.h"
typedef class HELOC final : public Account {
	double fee = 0;
public:
	HELOC();
	~HELOC();
	string Transaction(double) final;
} Checking;