// Part 1 - 
// Create a class Employee that has attributes name, department and salary.
// Create a constructor that intializes Employee objects.
// Create a member function that print these attributes

// Part 2 -
// Create a class manager which has attributes name, department and salary. The manager class has another attribute called bonus_percentage. Total salary of a manager is 


#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Employee {
  protected:
  string name;
  string department;
  double salary;

  public:
  Employee(string name, string department, double salary );
  void virtual print_details();
  void set_salary(double salary);
};

Employee::Employee(string name, string department, double salary){
  this->name = name;
  this->department = department;
  this->salary = salary;
}

void Employee::print_details(){
  cout<<"Name: "<<name<<endl;
  cout<<"Department: "<<department<<endl;
  cout<<"Salary: "<<salary<<endl;
}

void Employee::set_salary(double salary){
  this->salary = salary;
}

class Manager: public Employee {
  private:
  double bonus_percentage;
  public:
  Manager(string name, string department, double salary, double bonus_percentage);
void virtual print_details();
};

Manager::Manager(string name, string department, double salary, double bonus_percentage):Employee(name,department,salary) {
  this->bonus_percentage = bonus_percentage;
  this->salary = this->salary + this->salary*bonus_percentage*0.01;
}

void Manager::print_details() {
  cout<<"Name: "<<name<<endl;
  cout<<"Department: "<<department<<endl;
  cout<<"Bonus percentage: "<<bonus_percentage<<endl;
  cout<<"Salary: "<<salary<<endl;
}

int main() {
 Employee e1("Prajish","CSE",1000);
 //cout<<e1.name;
 Manager m1("Prajish","CSE",1000,5);
 Employee* e[2] = {&e1,&m1};

  for(int i=0;i<2;i++){
    e[i]->print_details();
  }
  
}