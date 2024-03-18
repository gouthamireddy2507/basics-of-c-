#include <iostream>
using namespace std;

class Employee{
protected:
string name;
string department;
float salary;

public:
Employee(string n, string d, float s): name(n), department(d), salary(s){};
void print(){
  cout<<"Name= "<<name<<endl;
  cout<<"Department= "<<department<<endl;
  cout<<"Salary = "<<salary<<endl;
}
};

class Manager: public Employee{

private:
float bonus;

public:
Manager(string n, string d, float s, float b): Employee(n,d,s),bonus(b){
  salary = salary+salary*bonus;
}

// void set_manager_salary(){
//   salary = salary+salary*bonus;
// }

};


int main() {
  Employee e1("ABC","XYZ",1000);
  Manager m1("ABC","XYZ",1000,0.5);
  //m1.set_manager_salary();
  m1.print();
}