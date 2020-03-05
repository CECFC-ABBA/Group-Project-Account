/*HELOC.cpp
 * Anela
 */

#include "HELOC.h"
#include <string>

HELOC::HELOC() {
    double houseval, mortgage;
    cout << "What is the current value of your property? ";
    cin >> houseval;
    cout << "What is your current mortgage? ";
    cin >> mortgage;
    months = getMonths();
    equity = houseval - mortgage;
    loan = equity - (equity * .2);
}

HELOC::~HELOC() {

}

double HELOC::Calculate(double) {
    
}

string HELOC::Transaction(double amt) {
    char user;
    cout << "Your maximum loan is worth: $" << loan << endl;
    cout << "Would you like to activate your HELOC?" << endl; //assuming user is eligible
    cin >> user;
    if ((user == 'Y') || (user == 'y')) {

    }
    return "";
}
