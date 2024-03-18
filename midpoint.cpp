#include <iostream>
using namespace std;
class Point {
private:
  float x;
  float y;
public:
  Point();
  Point(float xi, float yi);
  float getX() { return x; }
  float getY() { return y; }
  void setX(float xi) { x = xi; }
  void setY(float yi){y = yi;};
  void print();
  void move(float dx, float dy);
  void scale(float s);
};
Point::Point() {
  x = 0.0;
  y = 0.0;
}
Point::Point(float xi, float yi) {
  x = xi;
  y = yi;
}
void Point::print() { cout << "(" << x << "," << y << ")" << endl; }

void Point::move(float dx, float dy) {
  setX(x + dx);
  setY(y + dy);
}

void Point::scale(float s) {
  Point scaled;
  setX(x * s);
  setY(y * s);
}

Point midPoint(Point p, Point q) {
  Point mid;
  mid.setX((p.getX() + q.getX()) / 2);
  mid.setY((p.getY() + q.getY()) / 2);
  return mid;
}
int main() {
  Point p1, p2;
  Point p3(1, 2), p4(3, 4);
  p1.scale(10);
  p2.move(2, 3);
  Point p5 = midPoint(midPoint(p1, p3), midPoint(p2, p4));
  p5.print();

  Point p6=p5;
  p6.print();
}