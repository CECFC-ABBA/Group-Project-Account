#pragma once
#include "Account.h"
typedef class Savings final : public Account {
public:
	Savings();
	~Savings();
	string Transaction(double) final;
} Checking;