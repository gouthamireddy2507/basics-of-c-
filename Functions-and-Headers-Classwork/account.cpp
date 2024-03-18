#include <iostream>
using namespace std;

double deposit(double balance, double deposit_amount) {
  if (deposit_amount > 100000) {
    cout << "Your deposited exceeded the limit of 1 lakh" << endl;
  } else {
    balance = balance + deposit_amount;
  }
  return balance;
}

double withdraw(double balance, double withdraw_amount) {

  if ((balance - withdraw_amount) < 1000) {
    cout << "Withdrawal failed" << endl
         << "Your balance will fall below the minimum limit of Rs. 1000"
         << endl;
  } else {
    balance = balance - withdraw_amount;
  }
  return balance;
}

void print_balance(double balance) {
  cout << "Your Current balance is: Rs." << balance << endl;
}