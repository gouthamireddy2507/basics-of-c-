#include "account.h"
#include "gradebook.h"
#include <iostream>

using namespace std;

int main() {
  double balance = 1000;
  balance = deposit(balance, 10000);
  print_balance(balance);

  float gpa = calculate_gpa(40, 50, 60);
  char outcome = calculate_outcome(gpa);
  print_outcome_description(outcome);
}

// g++ -c account.cpp main.cpp
// g++ -o final main.o account.o
// ./final