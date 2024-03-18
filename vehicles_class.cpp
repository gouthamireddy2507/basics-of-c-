#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
  string brand;
  int year;

public:
  Vehicle(string b, int y) : brand(b), year(y) {}
  void displayInfo() {
    cout << "Brand: " << brand << ", Year: " << year << endl;
  }
};

class Car : public Vehicle {
private:
  int engine_capacity;

public:
  Car(string b, int y, int c) : Vehicle(b, y), engine_capacity(c) {}

  void displayInfo() {
    cout << "Car - ";
    Vehicle::displayInfo();
    std::cout << "Capacity" << engine_capacity << " cc" << endl;
  }
};

class Motorcycle : public Vehicle {
private:
  bool hasSidecar;

public:
  Motorcycle(string b, int y, bool sidecar)
      : Vehicle(b, y), hasSidecar(sidecar) {}

  void displayInfo() {
    cout << "Motorcycle - ";
    Vehicle::displayInfo();
    std::cout << "Has Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
  }
};

int main() {
  Car myCar("Toyota", 2022, 1000);
  Motorcycle myMotorcycle("Harley-Davidson", 2021, true);

  myCar.displayInfo();
  myMotorcycle.displayInfo();

  return 0;
}
