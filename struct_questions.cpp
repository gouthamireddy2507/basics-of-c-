#include <iostream>
using namespace std;

struct Point{
  static int counter;
  float x;
  float y;
  void print();
  void move(float dx, float dy);
  Point operator+ (Point p){
    return Point(this->x+p.x, this->y+p.y);
  }

  Point operator* (float s) {
    return Point(x*s, y*s);
  }
  void scale(float s);
  Point(){                            //Constructor
    x = 0.0;
    y = 0.0;
    counter++;
  }
  Point(float xi, float yi){
    cout<<"Inside Point's constructor - 2 float values";
    x = xi;
    y = yi;
    counter++;
  }
};

int Point::counter = 0;

void Point::print(){
  cout << "(" << x << "," << y << ")"<< endl;
}

void Point::move(float dx, float dy){
  Point moved;
  moved.x = x + dx;
  moved.y = y + dy;
  cout << "Moved point: ";
  moved.print();
}

void Point::scale(float s){
  Point scaled;
  scaled.x = x * s;
  scaled.y = y * s;
  cout << "Scaled point: ";
  scaled.print();
}

void midPoint(Point p, Point q){
  Point mid;
  mid.x = (p.x + q.x)/2;
  mid.y = (p.y + q.y)/2;
  cout << "Midpoint: ";
  mid.print();
}

struct Circle {
  Point center;
  float radius;

  // Circle(float x, float y, float radius){
  //   cout<<"Inside Circle's constructor"<<endl;
  //   this->radius = radius;
  //   Point center(x,y);
  // } // Commented this otherwise it will give an error

    Circle(float x, float y, float radius): center(Point(x,y)) , radius(radius){
      
    }
};

int main(){
  Circle c1(10,20,20);
  Point p0;
  Point p1(10,20);
  Point p2 = {20,30};
  Point p3 = p1 + p2;
  p3 = p1*10;
  p3.print();
  Point p4 = p3;
  p4.print();
}