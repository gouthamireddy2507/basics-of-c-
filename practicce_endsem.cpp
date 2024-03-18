/*
Write a program that reads a positive integer n and a digit d between 0 and 9. Use one or
more loops to count how many of the integers between 1 and n start with the digit d. 
*/
#include <iostream>

int countStartingDigit(int n, int d) {
    int count = 0;

    for (int i = 1; i <= n; ++i) {
        int firstDigit = i;

        while (firstDigit >= 10) {
            firstDigit /= 10;
        }

        if (firstDigit == d) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, d;
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;

    std::cout << "Enter a digit between 0 and 9: ";
    std::cin >> d;

    if (d < 0 || d > 9) {
        std::cout << "Invalid digit! Please enter a digit between 0 and 9." << std::endl;
        return 1;
    }

    int result = countStartingDigit(n, d);
    std::cout << "Number of integers between 1 and " << n << " starting with digit " << d << ": " << result << std::endl;

    return 0;
}

/*
The CoffeeNation outlet at FLAME needs your help to build its order software.
a. Create a structure MenuItem that has data members corresponding to the name of an item
and its cost. Create member functions to add new items to the menu.
b. Create a structure Order that takes several MenuItems from the user and calculates the
total bill. 
*/
#include <iostream>
#include <vector>
#include <string>

// Structure representing a menu item
struct MenuItem {
    std::string name;
    double cost;

    // Constructor to initialize MenuItem
    MenuItem(std::string itemName, double itemCost) : name(std::move(itemName)), cost(itemCost) {}
};

// Structure representing an order with multiple MenuItems
struct Order {
    std::vector<MenuItem> items;

    // Function to add a new item to the order
    void addItem(const MenuItem& newItem) {
        items.push_back(newItem);
    }

    // Function to calculate the total bill
    double calculateTotal() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.cost;
        }
        return total;
    }
};

int main() {
    Order order;

    // Adding items to the menu
    MenuItem item1("Coffee", 2.50);
    MenuItem item2("Sandwich", 5.75);
    MenuItem item3("Cake", 3.25);

    // Adding items to the order
    order.addItem(item1);
    order.addItem(item2);
    order.addItem(item3);

    // Calculating the total bill
    double totalBill = order.calculateTotal();

    // Displaying the total bill
    std::cout << "Total bill for the order: $" << totalBill << std::endl;

    return 0;
}

/*
An n × n matrix that is filled with the numbers 1, 2, 3,..., n2
 is a magic square if the sum of the
elements in each row, in each column, and in the two diagonals is the same value.
Write a program that reads in 16 values from the keyboard and tests whether they form a
magic square when put into a 4 × 4 array. You need to test two features:
1. Does each of the numbers 1, 2, ..., 16 occur in the user input?
2. When the numbers are put into a square, are the sums of the rows, columns, and
diagonals equal to each other?

*/

#include <iostream>
#include <vector>
#include <algorithm>

const int SIZE = 4;

// Function to check if each number from 1 to 16 exists in the input array
bool containsAllNumbers(const std::vector<int>& input) {
    std::vector<int> reference(16);
    std::iota(reference.begin(), reference.end(), 1); // Fill reference with 1 to 16

    for (int num : reference) {
        if (std::find(input.begin(), input.end(), num) == input.end()) {
            return false; // Number not found in input
        }
    }
    return true; // All numbers found
}

// Function to check if a 4x4 square is a magic square
bool isMagicSquare(const std::vector<std::vector<int>>& square) {
    int diagonalSum1 = 0, diagonalSum2 = 0;

    for (int i = 0; i < SIZE; ++i) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < SIZE; ++j) {
            rowSum += square[i][j];
            colSum += square[j][i];
            if (i == j) diagonalSum1 += square[i][j];
            if (i + j == SIZE - 1) diagonalSum2 += square[i][j];
        }
        if (rowSum != diagonalSum1 || colSum != diagonalSum1) return false;
    }

    return diagonalSum1 == diagonalSum2;
}

int main() {
    std::vector<int> input(16);

    std::cout << "Enter 16 numbers: ";
    for (int i = 0; i < 16; ++i) {
        std::cin >> input[i];
    }

    if (!containsAllNumbers(input)) {
        std::cout << "Input does not contain all numbers from 1 to 16." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> square(SIZE, std::vector<int>(SIZE));
    int index = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            square[i][j] = input[index++];
        }
    }

    if (isMagicSquare(square)) {
        std::cout << "The 4x4 square is a magic square!" << std::endl;
    } else {
        std::cout << "The 4x4 square is not a magic square." << std::endl;
    }

    return 0;
}

/*
Implement a C++ program to model fractions using a Fraction class. The class should have
the following functionalities:
1. A constructor to initialize the fraction with a numerator and a denominator. Ensure that
the denominator is not zero.
2. A display function to print the fraction in the form "numerator/denominator."
3. A add function that takes another Fraction object as a parameter and returns a new
Fraction object representing the sum of the two fractions.
4. A multiply function that takes another Fraction object as a parameter and returns a
new Fraction object representing the product of the two fractions.

*/

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int num, int denom) {
        if (denom == 0) {
            std::cout << "Error: Denominator cannot be zero. Setting denominator to 1." << std::endl;
            denominator = 1;
        } else {
            numerator = num;
            denominator = denom;
        }
    }

    // Display function
    void display() const {
        std::cout << numerator << "/" << denominator;
    }

    // Add function
    Fraction add(const Fraction& other) const {
        int num = (numerator * other.denominator) + (other.numerator * denominator);
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Multiply function
    Fraction multiply(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
};

int main() {
    Fraction frac1(1, 2); // Creating a fraction 1/2
    Fraction frac2(3, 4); // Creating a fraction 3/4

    std::cout << "Fraction 1: ";
    frac1.display();
    std::cout << std::endl;

    std::cout << "Fraction 2: ";
    frac2.display();
    std::cout << std::endl;

    Fraction sum = frac1.add(frac2); // Adding two fractions
    std::cout << "Sum of fractions: ";
    sum.display();
    std::cout << std::endl;

    Fraction product = frac1.multiply(frac2); // Multiplying two fractions
    std::cout << "Product of fractions: ";
    product.display();
    std::cout << std::endl;

    return 0;
}

/*
MiniSoft is a technology company that wants to develop an employee management system
for its employees. You are required to create a structure that stores information of
Employees of this organization.
Create a class Employee that contains the first name, last name, and the salary of the
employee
Create a constructor for Employee that takes the first name, last name, and salary as
parameters
Create another class called manager which contains the first name, last name and salary, as
well contains a list of employees that work under them. Create a member function
add_employee that adds an employee to the list
Create another member function that prints the total number of employees that work for a
manager and details of these employees
*/
#include <iostream>
#include <string>
#include <vector>

class Employee {
private:
    std::string firstName;
    std::string lastName;
    double salary;

public:
    Employee(const std::string& first, const std::string& last, double sal) : firstName(first), lastName(last), salary(sal) {}

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    double getSalary() const { return salary; }
};

class Manager {
private:
    std::string firstName;
    std::string lastName;
    double salary;
    std::vector<Employee> employees;

public:
    Manager(const std::string& first, const std::string& last, double sal) : firstName(first), lastName(last), salary(sal) {}

    void addEmployee(const Employee& emp) {
        employees.push_back(emp);
    }

    void printEmployees() const {
        std::cout << "Manager: " << firstName << " " << lastName << std::endl;
        std::cout << "Total employees under this manager: " << employees.size() << std::endl;
        std::cout << "Details of employees: " << std::endl;

        for (const auto& emp : employees) {
            std::cout << "Name: " << emp.getFirstName() << " " << emp.getLastName() << ", Salary: " << emp.getSalary() << std::endl;
        }
    }
};

int main() {
    Employee emp1("John", "Doe", 50000.0);
    Employee emp2("Alice", "Smith", 60000.0);

    Manager manager("Mary", "Johnson", 80000.0);
    manager.addEmployee(emp1);
    manager.addEmployee(emp2);

    manager.printEmployees();

    return 0;
}
/*
Professors at FLAME want a software that can help them create questions for quizzes.
Write a class Question that takes a question text and the correct answer as input. For
example, question text can be "Who is the inventor of C++". The answer is "Bjarne
Stroustrup".
Now, apart from creating a simple question, they would also like to create Multiple Choice
questions. Create another class Multiple_Choice_Question , which is a derived class of
Question , and has an attribute for storing choices (can be a vector of strings), and a correct
answer.
In the main function, create 4-5 questions of different types (both Question and
Multiple_Choice_Question ). Store them in a Question array.
Write a function that prints all the questions and answers in the Question array.
*/
#include <iostream>
#include <string>
#include <vector>

class Question {
private:
    std::string questionText;
    std::string answer;

public:
    Question(const std::string& text, const std::string& ans) : questionText(text), answer(ans) {}

    void printQuestion() const {
        std::cout << "Question: " << questionText << std::endl;
        std::cout << "Answer: " << answer << std::endl;
    }
};

class MultipleChoiceQuestion : public Question {
private:
    std::vector<std::string> choices;

public:
    MultipleChoiceQuestion(const std::string& text, const std::vector<std::string>& ch, const std::string& ans)
        : Question(text, ans), choices(ch) {}

    void printQuestion() const {
        Question::printQuestion();
        std::cout << "Choices: ";
        for (const auto& choice : choices) {
            std::cout << choice << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Question q1("Who is the inventor of C++?", "Bjarne Stroustrup");
    Question q2("What is the capital of France?", "Paris");

    std::vector<std::string> choices = { "Option A", "Option B", "Option C", "Option D" };
    MultipleChoiceQuestion mcq("What is 2+2?", choices, "4");

    // Store questions in an array
    Question questionsArray[] = { q1, q2, mcq };

    // Print all questions and answers in the array
    for (const auto& question : questionsArray) {
        question.printQuestion();
        std::cout << "---------------------------" << std::endl;
    }

    return 0;
}
