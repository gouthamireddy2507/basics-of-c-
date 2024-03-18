//LOOPS

// cubes of first 10 numbers

#include <iostream>
using namespace std;
int main() {
  int num = 1;
  while (num <= 10){
    cout<<num*num*num<<endl;
    num++;
  }
 }

// Program that "counts by 3" till 30
// using a while loop
#include <iostream>
using namespace std;
int main() {
  int num = 1;
  while (num <= 10){
    cout<<num*num*num<<endl;
    num++;
  }
  
}
// using a for loop

#include <iostream>
using namespace std;
int main(){
	for(int num=3; num<=30; num+=3){
		cout<<num<<endl;
	}
}

// Write a program that calculates the compound interest. Take the principal, interest rate and no of years 
//from the user. Show how much interest is generated every year. 
#include <iostream>
using namespace std;
int main(){
  float principal, interest, rate, no_of_years;
  cout<<"Enter the Principal, rate and no of years ";
  cin>>principal>>rate>>no_of_years;

  for (int i = 1; i<=no_of_years;i++){
    interest = principal*rate/100;
    cout<<"Interest in the year "<<i<< " ="<<interest<<endl;
    principal = principal + interest;
    cout<<"Amount at the end of the year "<<i<<" = "<<principal<<endl;
  }
}
// Write a program that prints all squares less than n. Take n from the user. 
// For example, if n is 100, print 0, 1, 4, 9, 25, 36, 49, 64, 81.
#include<iostream>
using namespace std;
int main(){
  int n;
  cout<<"Enter the number: " ;
  cin>>n;
  int num = 0;
  while (num*num<n){
    cout<<num*num<<endl;
    num++;
  }
}

//Write a program that keeps taking the user's marks one by one. When the user inputs -1,
//print the sum and average
#include<iostream>
using namespace std;

int main(){
  float mark, sum=0, average=0;
  cout<<"Enter the marks one by one ";
  cin>>mark;
  int n = 0;
  while(mark!=-1){
    sum = sum + mark;
    n++;
    cout<<"Enter the mark ";
    cin>>mark;
  }
  if (n!=0){
    average = sum/n;
    cout<<"Sum = "<<sum<<endl;
    cout<<"Average = "<<average<<endl;
  }
}

//Write a program that keeps taking the user's marks one by one. When the user inputs -1,
//print the largest mark
#include <iostream>
using namespace std;

int main(){
  float mark, largest = 0;
  cout<<"Enter the mark";
  cin>>mark;
  int n = 0 
  while (mark != -1){
    if(mark>largest)
      largest = mark;
    cout<<"Enter the mark";
    cin>>mark;
  }
  cout<<"Largest mark is "<<largest<<endl;
}
//Count the number of subjects having marks > 80

#include <iostream>
using namespace std;

int main(){
  float mark, mark_gt_80 = 0;
  cout<<"Enter the mark ";
  cin>>mark;
  //int n = 0;
  while(mark!=-1){
    if (mark>80)
      mark_gt_80++;
  cout<<"Enter the mark ";
  cin>>mark;
  }
  cout<<"The number of subjects with marks > 80 are: "<<mark_gt_80;
}

// Check if the input is between 0 and 100 - Prompting till match is found
#include <iostream>
using namespace std;

int main(){
  int input;
  cout<<"Enter the input: ";
  cin>>input;

  while(input < 0 || input > 100){
    cout<<" The input should be between 0 and 100"<<endl;
    cout<<"Enter the input: ";
    cin>>input;
  }
}
//The sum of all even numbers between 2 and 100 (inclusive)
#include<iostream>
using namespace std;

int main(){
  int sum = 0;
  for (int i=2;i<=100;i+=2){
    sum +=i;
  }
  cout<<sum;
}
// Write a program that calculates the sum of the digits of a number provided by the user.
// For example if the user inputs 1234, the output should be 10
#include<iostream>
using namespace std;

int main(){
  int num;
  cout<<"Enter the input value: ";
  cin>>num;
  int sum = 0;
  int last_digit;

  while(num!=0){
    last_digit = num % 10;
    sum = sum + last_digit;
    num = num/10;
  }
  cout<<"Sum of the digits = "<<sum<<endl;
}

//NESTED LOOPS

//Write a program that displays a rectangle of a given width and height.
//Take width and height as input from the user. Eg: width = 4 and height = 3.
/*
****
****
****
*/
#include <iostream>
using namespace std;

int main(){
  int width, height;
  cout<<"Enter the width: ";
  cin>>width;
  cout<<"Enter the height: ";
  cin>>height;

  for (int i = 0; i<height;i++){
    for (int j = 0; j<width;j++){
      cout<<"*";
    }
    cout<<endl;
  }
}

//Write a program that takes an input n from the user and prints the rows of 1, 2,...,n stars
//Eg: n = 4
/*
*
**
***
****
*/
#include <iostream>
using namespace std;

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0; j<=i;j++){
      cout<<"*";
    }
    cout<<endl;
  }
}
//Write a prgram that takes an input and prints whole square and a hallow square
//eg: if n = 5, the program prints
/*
***** *****
***** *   *
***** *   *
***** *   *
***** *****
*/
#include <iostream>
using namespace std;

int main(){
  int num;
  cout<<"Enter a number: ";
  cin>>num;

  for (int i = 0; i < num; i++){
    for (int j = 0; j < num; j++){
      cout<<"*";
    }
    cout<<" ";
    for(int j = 0; j < num; j++){
      if(i == 0 || i == num-1){
        cout<<"*";
      }else {
        if (j==0||j==num-1){
          cout<<"*";
        }else {
          cout<<" ";
        }
      }
    }
    cout<<endl;
  }
}
//Write a program that reads an integer and displays, using asterisks, a filled diamond of the given side length
//For example, if the side length is 4, the program should display
/*
   *
  ***
 *****
*******
 *****
  ***
   *
*/
#include <iostream>
using namespace std;
int main(){
	int i, j, rowNum, space;
	cout<<"Enter the number of rows: ";
	cin>>rowNum;
	space = rowNum-1;
	for(i = 1; i <= rowNum; i++){//start with the top part of the diamond}
		for (j = 1; j <= space; j++){
			cout<< " ";
		space--;
		for (j = 1;  j <= (2*i - 1); j++){//increase stars by 2 in each iteration
			cout<<"*";
		cout<<endl;
		}
		space = 1
		for (i = 1; i <=(rowNum-1);i++){//Move to the bottom part of the diamond
			for (j = 1; j <=space; j++){
				cout<<" ";
			space++;
			for (j = 1; j <=(2* (rowNum-i)-1);j++)//stars drecrease by 2
				cout<<"*";
			cout<<endl;
			}
		}
		}
	cout<<endl;
	return 0;
	}	
}

// Write a program  that takes a positive integer as input and prints 1 
// if it is prime and 0 otherwise

#include <iostream>

using namespace std;

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // 0 for numbers less than or equal to 1 (not prime)
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // 0 for numbers divisible by other numbers (not prime)
        }
    }
    return 1; // 1 for prime numbers
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    if (isPrime(number)) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }

    return 0;
}

// Write a program that a positive integer as input, 
// and prints the number of digits in that number.
#include <iostream>
using namespace std;

int countDigits(int num){
  int count = 0;

  while (num!=0){
    num = num/10;
    count++;
  }
  return count;
}

int main(){
  int number;
  cout<<"Enter a positive integer: ";
  cin>>number;
  
  if (number<=0){
    cout<<"Please enter a positive integer."<<endl;
  } 
  int digits = countDigits(number);
  cout<<"The number of digits in the given positive integer are: "<<digits<<endl;
}

//Write a program that takes a positive integer as input 
//and returns the number written in reverse. 
#include <iostream>
using namespace std;

int reverseNumber(int number){
    int reverse = 0;
    while (number > 0){
        int digit = number % 10;
        reverse = reverse * 10 + digit;
        number = number/10;
    }
    return reverse;
}

int main(){
    int n;
    cout<<"Enter a positive integer: ";
    cin>>n;
    if(n<=0){
        cout<<"Invalid input: Enter a positive integer"<<endl;
    }
    
    int reversedNumber = reverseNumber(n);
    cout<<"The reversed positive integer is: "<<reversedNumber<<endl;
}

// Write a program that reads in a sequence of characters, 
//one at a time, and stops as soon as it has
// read the contiguous sequence of characters – ‘s’, ‘t’, ‘o’, ‘p

#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    bool stopFound = false;

    cout << "Enter a sequence of characters (type 'stop' to end): ";

    // Keep reading characters until 'stop' is encountered
    while (cin >> input) {
        if (input == "stop") {
            stopFound = true;
            break;
        }
    }

    if (stopFound) {
        cout << "Sequence 'stop' encountered. Program stopped." << endl;
    } else {
        cout << "Sequence 'stop' not found. Program ended without encountering 'stop'." << endl;
    }

    return 0;
}

/*
In a forgotten laboratory deep within the depths of a mystical forest, scientists discovered a
peculiar substance with extraordinary properties. When exposed to the eldritch energies of the
forest, half of the substance decays or undergo some other process. In this problem, you will
write a program to calculate the remaining quantity of a substance after a certain number of time
units have passed.
Your program should take the initial quantity of the substance and the time it takes for one half of
that quantity to decay as input. Then, it should calculate and print the remaining quantity of the
substance after a specified number of time units.
Example:
Enter the initial quantity of the substance: 100.0
Enter the half-life of the substance: 5.0
Enter the number of time units that have passed: 10.0
Remaining quantity of the substance: 25.0000
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double initialQuantity, halfLife, timePassed;

    cout << "Enter the initial quantity of the substance: ";
    cin >> initialQuantity;

    cout << "Enter the half-life of the substance: ";
    cin >> halfLife;

    cout << "Enter the number of time units that have passed: ";
    cin >> timePassed;

    // Calculating the remaining quantity
    double remainingQuantity = initialQuantity * pow(0.5, (timePassed / halfLife));

    cout << "Remaining quantity of the substance: " << remainingQuantity << endl;

}

//Write a program that calculates the sum of all odd digits of an input.
//(For example, if the input is 32677, the sum would be 3 + 7 + 7 = 17.)
// Create a trace table to think about this problem before writing the program


#include <iostream>

using namespace std;

int main() {
    int inputNumber;
    cout << "Enter a number: ";
    cin >> inputNumber;

    int sumOfOddDigits = 0;
    int digit;

    while (inputNumber > 0) {
        digit = inputNumber % 10; // Extract the last digit
        if (digit % 2 != 0) { // Check if digit is odd
            sumOfOddDigits += digit; // Add odd digit to the sum
        }
        inputNumber /= 10; // Remove the last digit
    }

    cout << "Sum of odd digits: " << sumOfOddDigits << endl;
}

