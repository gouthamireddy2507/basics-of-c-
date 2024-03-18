#include <iostream>
using namespace std;

float calculate_gpa (float grade1, float grade2, float grade3){
  float sum = grade1 + grade2 + grade3;

  return sum/3.0;
}

char calculate_outcome(float gpa){
  char outcome;
  
  if (gpa == 100) {
    outcome = 'O';
  } else if (gpa >= 80 && gpa < 100) {
    outcome = 'A';
  } else if (gpa >= 60 && gpa < 80) {
    outcome = 'B';
  } else if (gpa >= 50 && gpa < 60) {
    outcome = 'C';
  } else if (gpa >= 40 && gpa < 50) {
    outcome = 'P';
  } else if (gpa < 40 && gpa >= 0) {
    outcome = 'F';
  } else {
    cout << "GPA out of range\n";
  }

  return outcome;
}

void print_outcome_description(char outcome){
    switch(outcome){ //Outcome can be 'O', 'A', 'B', 'C', 'P', 'F'
      
      default:
        cout<<"Error!!";
        break;
      
      case 'O':
        cout<<"Your grade is outstanding"<<endl;
        break;
      
      case 'A':
        cout<<"Your grade is excellent"<<endl;
        break;
      
      case 'B':
        cout<<"Your grade is good"<<endl;
        break;
      
      case 'C':
        cout<<"Your grade is average"<<endl;
        break;
      
      case 'P':
        cout<<"Your grade is pass"<<endl;
        break;
      
      case 'F':
        cout<<"Fail";
        break;
    }
}