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
//Each line is a transaction, format: `acct:bal_change`
//Acct is either checking, savings, or heloc.


//Main:
//Gets data from file, then outputs transaction results and final account specs. One account of each type.

void showContents(fstream& file) {
	string line;
	while (file >> line) { cout << line << endl; }
}

int main(int argc, char** argv) {
  dataFile.open("banking.txt", ios::out);
  bool openFileIn(fstream&, string);
	void showcontents(fstream&);
  Checking checking;
  Savings savings;
  HELOC heloc;
  checking.setBal(0);
  savings.setBal(0);
  heloc.setBal(0);
  if (argc > 2) {
    cout << "Too much input..." << endl;
    return 0;
  }
  else if (argc < 1) {
    cout << "Usage: <path> + filepath" << endl;
    return 0;
  }
  else {
    string filepath = argv[1];
    ifstream file;
    file.open(filepath);
    vector<string> filedata;
    string cur_line;
    do {
      cur_line = "";
      file >> cur_line;
      filedata.push_back(cur_line);
    } while(cur_line != "");
    for (string transaction : filedata) {
      string acct, bal_change_str;
      for (int i = 0; i < static_cast<int>(transaction.length()); i++) {
        if (transaction[i] != ':') {
          acct.push_back(toupper(transaction[i])); 
        }
        else if (i < static_cast<int>(transaction.length()) - 1) {
          for (int j = i + 1; j < static_cast<int>(transaction.length()); j++) {
            bal_change_str.push_back(transaction[j]);
          }
          break;
        }
        else {
          cout << "Something is wrong with your file." << endl;
          return 0;
        }
      }
      double bal_change = atof(bal_change_str.c_str());
      if (acct == "SAVINGS") {
        cout << savings.Transaction(bal_change) << endl;
      }
      else if (acct == "CHECKING") {
        cout << checking.Transaction(bal_change) << endl;
      }
      else {
        cout << heloc.Transaction(bal_change) << endl;
      }
    }
    cout << "Savings balance: " << savings.getBal() << endl;
    cout << "Checking balance: " << checking.getBal() << endl;
    cout << "HELOC balance: " << heloc.getBal() << endl;
    dataFile << "Account" << i << "Savings balance: " << savings.getBal() << endl;
    dataFile << "Account" << i << "Checking balance: " << checking.getBal() << endl;
    dataFile << "Account" << i << " HELOC balance: " << heloc.getBal() << endl;
  }
  return 1;
}
