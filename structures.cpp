//Structures

/*
Create a struct Point that has data variables x and y . Write member functions for the following
operations -
1. Prints the x and y coordinates of a point. Write the declaration of this function as a memo
here.
2. Moves a point by dx and dy . Write the declaration of this function as a memo here.
3. Scales a point by s . For example if p = (1,2), and s=2, p = (2,4) after scaling. Write the
declaration of this function as a memo here.
Write a separate non-member function that returns the midpoint of two Points p1 and p2
*/

#include <iostream>

struct Point {
    int x;
    int y;

    // Function to print x and y coordinates of a point
    void printCoordinates() {
        std::cout << "Point coordinates: (" << x << ", " << y << ")" << std::endl;
    }

    // Function to move a point by dx and dy
    void movePoint(int dx, int dy) {
        x += dx;
        y += dy;
    }

    // Function to scale a point by s
    void scalePoint(int s) {
        x *= s;
        y *= s;
    }
};

// Non-member function to find the midpoint between two points
Point midpoint(const Point& p1, const Point& p2) {
    Point mid;
    mid.x = (p1.x + p2.x) / 2;
    mid.y = (p1.y + p2.y) / 2;
    return mid;
}

int main() {
    // Usage examples:
    Point p = {1, 2};
    p.printCoordinates(); // Prints: Point coordinates: (1, 2)

    p.movePoint(2, 3);
    p.printCoordinates(); // Prints: Point coordinates: (3, 5)

    p.scalePoint(2);
    p.printCoordinates(); // Prints: Point coordinates: (6, 10)

    // Using the midpoint function
    Point p1 = {1, 2};
    Point p2 = {5, 6};

    Point mid = midpoint(p1, p2);
    mid.printCoordinates(); // Prints: Point coordinates: (3, 4)
}
