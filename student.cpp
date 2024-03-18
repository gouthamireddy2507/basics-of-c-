#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
public:
    // Accessors (getters)
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    // Mutators (setters)
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }
};
int main() {
  Student s;
  s.setName("ABC");
  s.setAge(20);

  cout<<s.getName()<<endl;
  cout<<s.getAge()<<endl;
}