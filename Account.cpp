#include "Account.h"

Account::Account() {
  
}

Account::~Account() {
 //delete[]this;
}

void Account::setBal(double new_bal) {
  bal = new_bal;
}

void Account::setIntr(double new_intr) {
  intr = new_intr;
}

void Account::setFee(double new_fee) {
  fee = new_fee;
}

void Account::setMonths(double new_months) {
    months = new_months;
}

string Account::Transaction(double) {
    return ""; 
}
