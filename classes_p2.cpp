#include <iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class MenuItem {
    
    string name;
    int cost;

    public:
    void add_item(string n,int c);
    int get_cost() {
      return cost;
    }
};

void MenuItem::add_item(string n, int c) {
  name = n;
  cost = c;
}

class Order {
  MenuItem menu_items[10];
  int counter;
  double total_bill;

  public:
  void add_menu_item(MenuItem m);
  void calculate_total_bill();

  Order() {
    counter=0;
  }
};
void Order::calculate_total_bill() {
  total_bill=0;
  for(int i=0;i<counter;i++){
    int c = menu_items[i].get_cost();
    cout<<"c==="<<c<<endl;
    total_bill = total_bill + c;
  }
  cout<<"Total bill = "<<total_bill;
}
void Order:: add_menu_item(MenuItem m) {
  menu_items[counter] = m;
  counter++;
}

// int main() {
//   MenuItem m1;
//   m1.add_item("Coffee",60);
  
//   MenuItem m2;
//   m2.add_item("Tea",60);

//   Order o;
//   o.add_menu_item(m1);
//   o.add_menu_item(m2);
//   o.calculate_total_bill();
  
  
// }