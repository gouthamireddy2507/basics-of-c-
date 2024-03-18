// #include <iostream>
// using std::cout;
// using std::endl;
// using std::cin;
// void swap(int a,int b){
//   int temp;
//   temp=a;
//   a=b;
//   b=temp;
// }

// void another_swap(int *a, int *b) {
//   int *temp;
//   temp=a;
//   a=b;
//   b=temp;
// }

// void array_fun(int arr[]){
//   cout<<*arr<<endl;
//   cout<<*(arr+1)<<endl;
// }

// int InputMarks(int marks[100][2]){
//   int i;
//   for(i=0;i<100;i++){
//     cout<<"Enter Roll no";
//     cin>>marks[i][0];
//     if(marks[i][0]<0)
//       break;
//     cout<<"Enter Marks";
//     cin>>marks[i][1];
//   }
//   return i-1;
// }

// void PrintMarks(int marks[100][2], int no_of_students){
//   for(int i=0;i<=no_of_students;i++){
//     cout<<"Roll No: "<<marks[i][0]<<"   ";
//     cout<<"Marks: "<<marks[i][1]<<endl;
    
//   }
// }

// int main() {
//   //Swap Program
//   int a=5,b=10;
//   cout<<"Calling ordinary swap"<<endl;
//   swap(a,b);
//   cout<<"a== "<<a<<endl;
//   cout<<"b=="<<b<< endl;

//   //Pointers
//   cout<<"Calling another_swap"<<endl;
//   another_swap(&a, &b);
//   cout<<"a== "<<a<<endl;
//   cout<<"b=="<<b<< endl;

//   //Address
//   int arr[] = {0,1,2,3,4};
//   cout<<"Address of arr[0]=="<<arr<<endl;
//   cout<<"Address of arr[1]=="<<arr+1<<endl;
//   cout<<"Address of arr[2]=="<<arr+2<<endl;
//   array_fun(arr);

//   //Arrays degrade to pointers
//   int *arr1 = arr;
//   *(arr1+1) = 100;
//   cout<<arr[1];

//   //2D arrays
//   int two_d_array[2][2] = {{1,2},{3,4}};
//   cout<<two_d_array[1][0];
  
//   //Revisiting marks
//   int marks[100][2];
//   int no_of_students=InputMarks(marks);

//   PrintMarks(marks,no_of_students);


//   // Character Array
//   char countries[3][40] = {"United States of America","China","Russia"};
//   cout<<countries[0]<<endl;
//   cout<<*(countries+2)<<endl;

//   cout<<*(countries+2)[0]<<endl;

//   for(int i=0; i<10;i++) {
//     for(int i=0;i<10;i++)
//       cout<< i << " ";
//     cout<<endl;
//   }
    
// }