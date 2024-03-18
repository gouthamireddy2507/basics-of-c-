// #include <iostream>
// #include <cmath>
// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;

// struct Point {
//   float x;
//   float y;
//   static int counter;
//   Point() {
//     counter++;
//   }

//   Point(float x,float y) {
//     this->x = x;
//     this->y = y;
//     counter++;
//   }
//   void print();
//   void move(float dx, float dy);
//   //Point midpoint(Point p1, Point p2);

// };

// int Point::counter = 0;
// void Point:: print() {
//   cout<<"X coordinate ="<<x<<endl;
//   cout<<"Y coordinate ="<<y<<endl;
// }

// void Point:: move(float dx, float dy)  {
//   x+=dx;
//   y+=dy;
// }

// Point midpoint(Point p1, Point p2) {
//   Point midpoint;
//   midpoint.x=(p1.x + p2.x)/2;
//   midpoint.y=(p1.y+p2.y)/2;
//   return midpoint;
// }

// struct Line {
//   Point p1;
//   Point p2;

//   Line(Point p1, Point p2) {
//     this->p1 = p1;
//     this->p2 = p2;
//   }
//   double length();
//   double slope();
// };

// double Line::length() {
//   return sqrt(pow((p2.x - p1.x),2) - pow((p2.y - p1.y),2));
// }

// double Line::slope(){
//   return (p2.y-p1.y)/(p2.x-p1.x);
// } 
// int main(){
//   Point p1 = {0.0,0.0};
//   Point p2 = {0.5,0.5};

//   Line l = Line(p1,p2);
//   cout<<l.slope()<<endl;
//   cout<<l.length()<<endl;
//   p1.print();
//   p2.print();

//   Point p3 = midpoint(p1,p2);
//   p3.print();
  
//   cout<<Point::counter;
// }