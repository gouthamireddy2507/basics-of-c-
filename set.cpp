#include <iostream>
#include <vector>
using std::vector;
class Set
{
public:
 Set(){size=-1;}
 void add(int n);
 bool contains(int n) const;
 int get_size() const;
 void print();

private:
 vector<int> elements;
 int size;
};

bool Set::contains(int n) const {
  for(int i=0;i<size;i++){
    if(elements[i]==n)
      return true;
  }
  return false;
}
void Set::add(int n) {
  if(!contains(n)){
    elements[++size] = n;
  } 
}

int Set::get_size() const {
  return size;
}

void Set::print() {
  for(int i=0;i<size;i++)
    std::cout<<elements[i]<< " ";
  std::cout<<std::endl;
}
int main() {
  Set s1;
  s1.add(1);
  s1.add(2);
  s1.print();
}