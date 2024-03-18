#include <iostream>

using std::cout;
using std::endl;
using std::cin;

bool identity_matrix(int a[][3]){
  return true;
}

int main() {
  int a[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++) {
      cin>>a[i][j];
    }
  }

  cout<<identity_matrix(a);
  
  // char a[10] = "adfbjabdf";
  // cout<<a[1]<<endl;
  char s[10];

  // cin>>s;
  // cout<<s;

  cin.getline(s,10);
  cout<<s;

  
}