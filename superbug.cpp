#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int LEFT = -1;
const int RIGHT = 1;

class Bug {
  protected:
    int position;
    int direction;
  public:
    Bug(int initial_position);
    void turn();
    void move();
    int get_position() const;
};

Bug::Bug(int initial_position) {
  this->position = initial_position;
  this->direction = RIGHT;
}

void Bug::turn(){
  if(direction == LEFT)
   direction = RIGHT;
  else
    direction = LEFT;
}

void Bug::move(){
  position = position + direction;
}

int Bug::get_position() const{ 
  return position;
}

class SuperBug:public Bug{
  public:
  SuperBug(int initial_position): Bug(initial_position){
    
  }
  void move(int steps){
    position+=steps;
  }
};

// int main() {
//   Bug b(10);
//   b.move();
//   b.turn();
//   b.move();
//   cout<<b.get_position()<<endl;

//   SuperBug sb(10);
//   sb.move(10);
//   cout<<sb.get_position()<<endl;
// }