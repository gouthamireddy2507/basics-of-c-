#include <iostream>
using namespace std;
void practice(int a, int b) {
  if (a < b) {
    a = a + 2;
  }
  if (a > b) {
    a = a - 2;
  }
  cout << a + b;
}

double k(double x) { return 2 * (x + 1); }
double h(double x) { return x * x + k(x) - 1; }
double g(double x) { return 4 * h(x); }

int main() {
  int i, j;
  for (i = 1; i <= 5; i++) {
    for (j = 1; j <= 7; j++) {
      if ((i + j) % 2 == 0) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}
