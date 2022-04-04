#include <iostream>
#include <iomanip>
// #include "Console.hpp"

using namespace std;

class Console {
  public:
    float readNumber(string prompt) {
      float value;
      cout << prompt;
      cin >> value;
      return value;
    }
};

class Calculator {
  public:
    // calculate yearly interest without additional monthly deposit
    // calculate Year End Earned Interest
    float calculateInterest(float &totalAmount, float annualInterest, float &initialAmount) {
      initialAmount = totalAmount * (annualInterest / 100);
      return initialAmount;
    }

    // calculate Year End Balance
    float calculateBalance(float &totalAmount, float &initialAmount) {
      totalAmount = totalAmount + initialAmount;
      return totalAmount;
    }

    // calculate yearly interest with additional monthly deposits
    // calculate Year End Earned Interest + monthly deposits
    float calculateInterest(float &totalAmount, float annualInterest, float &initialAmount, float monthlyDeposit) {
      initialAmount = (totalAmount + monthlyDeposit) * ((annualInterest / 100) / 12);
      return initialAmount;
    }

    // // calculate Year End Balance + monthly deposits
    float calculateBalance(float &totalAmount, float &initialAmount, float monthlyDeposit) {
      totalAmount = totalAmount + initialAmount + monthlyDeposit;
      return totalAmount;
    }

};

class Report {
  private:
    Calculator balanceCalculator;

  public:
    void printWithoutMonthlyDeposits(float years, float &totalAmount, float annualInterest, float &initialAmount) {
      cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
      cout << "==============================================================\n";
      cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
      cout << "--------------------------------------------------------------\n";

      // loop over years from user input
      for (int i = 0; i < years; i++) {
        // calculate Year End Earned Interest
        float yearEndEarnedInterest = balanceCalculator.calculateInterest(totalAmount, annualInterest, initialAmount);
        // calculate Year End Balance
        float yearEndBalance = balanceCalculator.calculateBalance(totalAmount, initialAmount);
        // print to console calculated balance and interest for every year
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << yearEndBalance << "\t\t\t$" << yearEndEarnedInterest << "\n";
      }
    }

    void printWithMonthlyDeposits(float years, float &totalAmount, float annualInterest, float &initialAmount, float monthlyDeposit) {
      cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
      cout << "==============================================================\n";
      cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
      cout << "--------------------------------------------------------------\n";

      // loop over years from user input
      for (int i = 0; i < years; i++) {
        // set yearly interest to 0 at start of loop
        int yearlyInterest = 0;
        float balance;
        // loop over each month
        for (int j = 0; j < 12; j++) {
          // calculate Month End Earned Interest + monthly deposits
          float monthlyInterest = balanceCalculator.calculateInterest(totalAmount, annualInterest, initialAmount, monthlyDeposit);
          yearlyInterest = yearlyInterest + monthlyInterest;
          balance = balanceCalculator.calculateBalance(totalAmount, monthlyInterest, monthlyDeposit);
        }
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << balance << "\t\t\t$" << yearlyInterest << "\n";
      }
    }
};

int main () {
  Console userInput;
  Report balanceReport;
  cout << "Hello" << endl;
  float initialAmount = userInput.readNumber("Initial Investment Amount: $");
  float monthlyDeposit = userInput.readNumber("Monthly Deposit: $");
  float annualInterest = userInput.readNumber("Annual Interest: %");
  float numOfYears = userInput.readNumber("Number of years: ");

  float initialInvestment = initialAmount;

  float total = initialAmount;
  balanceReport.printWithoutMonthlyDeposits(numOfYears, total, annualInterest, initialAmount);

  total = initialInvestment;
  balanceReport.printWithMonthlyDeposits(numOfYears, total, annualInterest, initialInvestment, monthlyDeposit);


  return 0;
}

