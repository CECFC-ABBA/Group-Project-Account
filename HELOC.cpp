/*HELOC.cpp
 * ABBA group memeber(s): Brendan McCleery, Anela Gallegos
 * 3 March 2020
 *	Purpose:
 * Everything in the HELOC class will be defined here.
 * This will keep track of home equity, the loan(and interest rate), and the fee being payed.
 * (No fee(?), Charges, Interest)
 *  The user will be enabled to see there current home equity. What kind of loan they can pull based off of that, with a random interest fee. 
 * It will display how many months is needed to pay off that loan and your current equity after pulling the loan.
 *
 */

#include "HELOC.h"
#include <string>

HELOC::HELOC() {
    double houseval = 0, mortgage = 0;
    cout << "What is the current value of your property? ";
    cin >> houseval;
    cout << "What is your current mortgage? ";
    cin >> mortgage;
    months = 0;
    equity = houseval - mortgage;
    loan = equity - (equity * .2);
}

HELOC::~HELOC() {

}

string HELOC::Transaction(double amt) {
    char user, input, temp, /*userChoice, */choice;
    cout << "Do you have an existing HELOC?\n (1) Yes (2) No\nInput 1 or 2 then [Enter]\n";
        cin >> user;
    if (user = 1) choice = 1;
    if (user = 2) choice = 2;
    //if (user != 1 || user != 2) choice = 3;
    else {choice = 3;}
    switch (choice) {
    case 1:
        //User Has existing HELOC
        cout << "What would you like to view from your HELOC?\n(1) Remaining Payment: \n"
            << "(2) Current interest: \n(3) Home Equity:" << endl;
        cin >> user;

        if (user = 1) {
            cout << "The Remaining payment in your HELOC is " << /**/ << endl;
            
        }

        if (user = 2) {
            cout << "The current interest on your HELOC is " << /**/ << endl;

        }

        //May not be needed
        if (user = 3) {
            cout << "The current value of your home equity is? " << /**/ << endl;

        }
            break;

    case 2:
        //User is creating a HELOC(maybe?)
        cout << "Your maximum loan is worth: $" << loan << endl;
        cout << "Would you like to activate your HELOC?" << endl; //assuming user is eligible
        cin >> user;
        if ((user == 'Y') || (user == 'y')) {
            cout << "For the first ten years of your loan, you will owe " << intr1 << "%." << endl;
            cout << "After the ten years of the drawing period is up, you will pay back what has been spent plus an interest of " << intr2 << "%." << endl;
            cout << "Would you like to draw from your loan now? (y/n): ";
            cin >> input;
            if ((input == 'Y') || (input == 'y')) {
                if (amt > loan) {
                    cout << "Your previously selected value was too large, please enter a new value." << endl;
                    cin >> amt;
                    loan -= amt;
                }
                else {
                    cout << "Previously you wanted to draw $" << amt << ".\nIs this still accurate? (y/n): ";
                    cin >> temp;
                    if ((temp == 'y') || (temp == 'Y')) loan -= amt;
                    else if ((temp == 'n') || (temp == 'N')) {
                        cout << "Please enter a new amount: $";
                        cin >> amt;
                        amt -= loan;
                    }
                }
            }
            cout << "You have " << loan << " remaining." << endl;
            amt* intr1;
            cout << "Currently you will owe $" << amt << "." << endl;
        }
            break;
        default:
            break;

    }
    string trans = to_string(loan);
    return trans;
}
