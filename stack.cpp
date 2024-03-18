#include <iostream>

const int MAX_SIZE = 10; // Maximum size of the stack

class Stack {
private:
  int arr[MAX_SIZE];
  int top; // Index of the top element

public:
  // Constructor to initialize an empty stack
  Stack() : top(-1) {}

  // Member function to push an element onto the stack
  void push(int value) {
    if (top == MAX_SIZE - 1) {
      std::cout << "Stack Overflow. Cannot push more elements.\n";
      return;
    }
    arr[++top] = value;
    std::cout << "Pushed: " << value << "\n";
  }

  // Member function to pop an element from the stack
  void pop() {
    if (isEmpty()) {
      std::cout << "Stack Underflow. Cannot pop from an empty stack.\n";
      return;
    }
    std::cout << "Popped: " << arr[top--] << "\n";
  }

  // Member function to peek at the top element without removing it
  void peek() const {
    if (isEmpty()) {
      std::cout << "The stack is empty.\n";
    } else {
      std::cout << "Top Element: " << arr[top] << "\n";
    }
  }

  // Member function to check if the stack is empty
  bool isEmpty() const { return top == -1; }

  // Member function to display the elements of the stack
  void display() const {
    if (isEmpty()) {
      std::cout << "The stack is empty.\n";
    } else {
      std::cout << "Stack Elements: ";
      for (int i = 0; i <= top; ++i) {
        std::cout << arr[i] << " ";
      }
      std::cout << "\n";
    }
  }
};

Stack stack_union(Stack s1, Stack s2) {
  Stack s3;
  while (!s1.isEmpty()) {
    s3.push(s1.pop());
  }
}
int main() {
  Stack myStack;

  myStack.push(5);
  myStack.push(10);
  myStack.push(15);
  myStack.display(); // Stack Elements: 5 10 15

  myStack.pop();     // Popped: 15
  myStack.display(); // Stack Elements: 5 10

  myStack.peek(); // Top Element: 10

  myStack.pop();     // Popped: 10
  myStack.pop();     // Popped: 5
  myStack.pop();     // Trying to pop from an empty stack
  myStack.display(); // The stack is empty
}