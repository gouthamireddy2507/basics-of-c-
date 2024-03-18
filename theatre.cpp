#include <iostream>
using namespace std;

int pick_seat(int theater[][10], int user_row, int user_col) {
  
}

int pick_price(int theater[][10], int price) {
  
}
int main() {
  int theater[9][10] = {{10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                        {10, 10, 20, 20, 20, 20, 20, 20, 10, 10},
                        {10, 10, 20, 20, 20, 20, 20, 20, 10, 10},
                        {10, 10, 20, 20, 20, 20, 20, 20, 10, 10},
                        {20, 20, 30, 30, 40, 40, 30, 30, 20, 20},
                        {20, 30, 30, 40, 50, 50, 40, 30, 30, 20},
                        {30, 40, 50, 50, 50, 50, 50, 50, 40, 30}};
  int sale = 0;

  int choice;
  cout << "1. Pick a seat\n 2. Pick a row and col\n Enter -1 to exit";
  cin >> choice;

  while (choice != -1) {
    if (choice == 1) {
      // Option - User picks a seat
      int row, col;
      cout << "Enter the row ";
      cin >> row;
      cout << "Enter the column";
      cin >> col;
      int result = pick_seat(theater, row, col);
      if (result != -1) {
        sale = sale + result;
      } else {
        cout << "Ticket not available. Please try again";
      }
    } else if (choice == 2) {
      // Option - User picks a price;
      int price;
      cout << "Enter a price: ";
      cin>>price;
      int result = pick_price(theater, price);
      if (result != -1) {
        sale = sale + result;
      } else {
        cout << "Ticket with price " << price
             << " not available. Please try again";
      }
    }
    cout << "1. Pick a seat\n 2. Pick a row and col\n Enter -1 to exit";
    cin >> choice;
  }
  cout<<"Total sales = "<<sale<<endl;
}