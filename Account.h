#pragma once
#include <iostream>
using namespace std;
typedef class Account {
	double bal;
	double intr;
	double fee;
	double months;
public:
	Account();
	virtual ~Account();
	double getBal() const {
		return bal;
	}
	double getIntr() const {
		return intr;
	}
	double getFee() const {
		return fee;
	}
	double getMonths() const {
		return months;
	}
	void setBal(double);
	void setIntr(double);
	void setFee(double);
	void setMonths(double);
	virtual string Transaction(double);
} Account;
