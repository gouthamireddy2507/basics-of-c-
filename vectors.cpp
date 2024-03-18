#include <iostream>
#include <vector>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void print(vector<int> v) {
  for(int element:v) // Another way to iterate through a vector. The usual way is for(int i=0;i<v.size();i++)
    cout<<element<<" ";
  cout<<endl;
}

vector<int> operator ^(vector<int> v, int e) {
  for(int i=0;i<v.size();i++)
    v[i] = pow(v[i],e);

  return v;
}
int main() {
  vector<int> v1; //One way to initialize a vector
  cout<<v1.size()<<endl; //size of this vector is 0.
  
  vector<int> v2 = {1,2,3,4,5,6,7,8,9,10}; // Another way to initialize a vector
  cout<<v2.size()<<endl; //size of this vector is 10.
  
  vector<int> v3(10); // 3rd way to initialize a vector - all elements are initialised to 0
  
  v3 = {1,2,3,4,5,6,7,8,9,10,11}; // Although we initialised the size of v3 to 10, we can add additional elements in the definition
  cout<<"Size of v3 = "<<v3.size()<<endl; //Size is 11
  
  v3[11] = 12; // This won't work, although it won't give an error. Size still remains 11
  cout<<"Size of v3, even after adding one more element = "<<v3.size()<<endl; //Size is 11
  
  v3.push_back(12); //This will add '12' at the end of the vector

  print(v3);

  v3.pop_back(); // This will remove the last element in the vector

  //If I want to retrieve the last element
  int last_position = v3[v3.size()-1];
  v3.pop_back();
  cout<<last_position<<endl;
  
  vector<int> v5(10,5); // This adds 10 elements to the vector, all with value 5
  v5 = v5^2; // Operator overloading. Check the ^ function above
  print(v5);

  //Inserting an element
  //https://cplusplus.com/reference/vector/vector/insert/

}