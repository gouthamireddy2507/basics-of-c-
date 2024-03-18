// #include <iostream>

// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;
//   struct Student {
//     string name;
//     string address;
//     int marks[6];
//     int total=0;
//     float average;
//     static int counter;
//     void print_inside_structure();
//   };

// void print(Student s){
//   cout<<"Name = "<< s.name<<endl;
//   cout<<"Address = "<< s.address<<endl;
//   cout<<"Marks = ";
//   for(int i=0;i<6;i++)
//     cout<<s.marks[i]<< " ";
//   cout<< "Total = "<<s.total<<endl;
// }

// void Student::print_inside_structure(){
//   // This function is a member function of the structure itself, and hence we need not pass the structure variable, unlike the print method defined above
//   cout<<"Name = "<< name<<endl;
//   cout<<"Address = "<< address<<endl;
//   cout<<"Marks = ";
//   for(int i=0;i<6;i++)
//     cout<<marks[i]<< " ";
//   cout<< "Total = "<<total;
// }
// void total_call_by_value(Student s) {
//   for(int i=0;i<6;i++)
//     s.total+=s.marks[i];
// }

// void total_call_by_reference(Student *s) {
//   for(int i=0;i<6;i++)
//     //(*s).total+=(*s).marks[i];
//     s->total+=s->marks[i];
// }

// void student_input(struct Student student[5]){
//   for(int i=0;i<5;i++){
//     cin>>student[i].name;
//     cin>>student[i].address;
//     for(int j=0;j<6;j++){
//       cin>>student[i].marks[j];
//     }
//   }
// }
// int Student::counter = 0;
// int main(){
//   Student s1 = {"S1","ABCD",{1,2,3,4,5,6}};
//   Student s2 = {"S2","dgadf",{10,20,30,40,50,60}};
//   Student s3 = {"S3", "adfadf",{30,40,50,60,70,80}};
//   Student s4 = {"S4","adfadfdaf",{90,90,90,90,90,90}};
//   Student s5 = {"S5","adfaf",{80,70,60,50,40,30}};

//   Student::counter = 5;
//   cout<<"Call by Value - It will not compute the total\n";
//   total_call_by_value(s1);
//   print(s1);

//   cout<<"Call by Reference\n";
//   total_call_by_reference(&s1);
//   print(s1);

//   s1.print_inside_structure();

//   cout<<"Total no of students == "<<Student::counter<<endl;
//   Student students[5];
  
//   // Student students[0] = {"S1","ABCD",{1,2,3,4,5,6}};
//   // Student students[1] = {"S2","dgadf",{10,20,30,40,50,60}};
//   // Student students[2] = {"S3", "adfadf",{30,40,50,60,70,80}};
//   // Student students[3] = {"S4","adfadfdaf",{90,90,90,90,90,90}};
//   // Student students[4] = {"S5","adfaf",{80,70,60,50,40,30}};

//   student_input(students);
//   cout<<students[0].name;
// }