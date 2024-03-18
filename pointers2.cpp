#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// Suppose the array primes, defined as
// int primes[] = { 2, 3, 5, 7, 11, 13 };
// starts at memory location 20300. What are the values of
// 	a. primes
// 	b. *primes
// 	c. primes + 4 
// 	d. *(primes + 4)
// 	e. primes[4]
// 	f. &primes[4]

int main(){
  int primes[] = {2,3,5,7,11,13};
  cout<<primes<<endl;

  cout<<*primes<<endl;

  cout<<primes+4<<endl;

  cout<<*(primes+4)<<endl;
}