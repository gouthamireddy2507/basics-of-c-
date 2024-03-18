#include <iostream>
using namespace std;
int main() {
  int i, j, rowNum, space;
  cout << "Enter the Number of Rows: ";
  cin >> rowNum;
  space = rowNum - 1;
  for (i = 1; i <= rowNum; i++) { // Start with the top part of the diamond
    for (j = 1; j <= space; j++)
      cout << " ";
    space--;                           // Spaces reduce by 1n each iteration
    for (j = 1; j <= (2 * i - 1); j++) // Stars increase by 2 in each iteration
      cout << "*";
    cout << endl;
  }
  space = 1;
  for (i = 1; i <= (rowNum - 1);
       i++) {                    // Move to the bottom part of the diamond
    for (j = 1; j <= space; j++) // Spaces increase by 1
      cout << " ";
    space++;
    for (j = 1; j <= (2 * (rowNum - i) - 1); j++) // Stars decrease by 2
      cout << "*";
    cout << endl;
  }
  cout << endl;
  return 0;
}