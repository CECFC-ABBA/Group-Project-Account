 /* This is the Checking class Inherrited from Account. 
 * It will serve to create an overdraft for expenses which to not fit a budget 
 * Period 3
 * 4 March 2020
 */
#pragma once
#include "Account.h"
typedef class Checking final : public Account {/*Typedef is being ignored by the compiler*/
	double intr, fee, bal, overDraft;
public:
	Checking();
	//~Checking();
	string Transaction(double) final;
	double getOverDraft() const {
		return overDraft;
	}
} Checking;
