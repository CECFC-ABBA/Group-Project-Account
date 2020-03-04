/*This is the main test program for the Github banking project
Created by the ABBA team
Period 3 Computer Science
Febuary 27th 2020*/

#include "Savings.h"
#include "HELOC.h"
#include "Checking.h"
//#include "Account.h"
#include <vector>
#include <ostream>
#include <sstream>
#include <fstream>

//File specs:
//Each line is a transaction, format: `acct{acct_num}:bal_change`
//Acct is either checking, savings, or heloc.

//Print:
//Prints final account specs

void print(vector<double> list, string str) {
  for (int i = 0; i < static_cast<int>(list.size()); i++) {
    cout << "Balance in " << str << " " << i << " : " << list[i] << endl;
  }
}

//Main:
//Gets data from file, then outputs transaction results and final account specs.
//Number of accounts of each type entered when this is run.

#ifdef FANCYMAIN

int main(int argc, char** argv) {
  
#else

int altMain(int argc, char** argv) {

#endif
  
  if (argc > 3) {
    cout << "Too much input..." << endl;
    return 0;
  }
  else if (argc < 2) {
    cout << "Usage: <path> + filepath + number of each type of account" << endl;
    return 0;
  }
  else {
    string filepath = argc[1];
    int acctNum = atoi(argc[2].c_str());
    Checking checking[acctNum], Savings savings[acctNum], HELOC heloc[acctNum];
    ifstream file;
    file.open(filepath);
    vector<string> filedata;
    string cur_line;
    do {
      file >> cur_line;
      filedata.push_back(cur_line);
    } while(cur_line != "");
    for (string transaction : filedata) {
      string acct, bal_change_str, num_str;
      for (int i = 0; i < static_cast<int>(transaction.length()); i++) {
        if (transaction[i] != '{') {
          acct.push_back(toupper(transaction[i])); 
        }
        else if (i < static_cast<int>(transaction.length()) - 1) {
          for (int j = i; j < static_cast<int>(transaction.length(); j++) {
            if (transaction[j] != '}') {
              num_str.push_back(transaction[j]); 
            }
            else if (j < static_cast<int>(transaction.length() - 2; k++) {
              for (int k = j; k < static_cast<int>(transaction.length()) {
                bal_change_str.push_back(transaction[j]);
              }
            }
            else {
              cout << "Something is wrong with your file." << endl;
              return 0; 
            }
          }
          break;
        }
        else {
          cout << "Something is wrong with your file." << endl;
          return 0;
        }
      }
      double bal_change = atoi(bal_change_str.c_str());
      double num = atoi(num_str.c_str());
      if (acct == "SAVINGS"){
        cout << savings[num].Transaction(bal_change) << endl;
      }
      else if (acct == "CHECKING"){
        cout << checking[num].Transaction(bal_change) << endl;
      }
      else {
        cout << heloc[num].Transaction(bal_change) << endl;
      }
    }
    vector<double> savingsBal, checkingBal, helocBal;
    for (Savings s : savings) {
      savingsBal.push_back(s.getBal()); 
    }
    for (Checking c : checking) {
      checkingBal.push_back(c.getBal()); 
    }
    for (HELOC h : heloc) {
      helocBal.push_back(h.getBal()); 
    }
    print(savingsBal, "savings");
    print(checkingBal, "checking");
    print(helocBal, "heloc");
  }
  return 1;
}
