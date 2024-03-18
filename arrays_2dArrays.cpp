//ARRAYS

/*
From the keyboard, read in a sequence of numbers, each denoting the marks obtained by students in a
class. The marks are known to be in the range 0 to 100. The number of students is not told explicitly. If
any negative number is entered, it is not to be considered the marks of any student, but merely a signal
that all marks have been entered.
Upon reading a negative number, the program should print the average mark by the students and stop.
Rewrite this program such that it stores each students' mark as an array element. You can assume
that the class has less than 100 students. Again, if any negative mark is entered, it is not to be
considered the marks of any student, but merely a signal that all marks have been entered.
In addition, write the following functions -
1. Calculate the average of the class
2. Calculate the highest mark in the class
3. Calculate number of students scoring less than 40 out of 100
4. Calculate how many students have got between 0 and 9, 10 and 19, 20 and 29 and so on (this
is known as a histogram) 
*/

#include <iostream>

using namespace std;

const int MAX_STUDENTS = 100;

void calculateStatistics(int marks[], int numStudents) {
    // Calculate average
    int sum = 0;
    for (int i = 0; i < numStudents; ++i) {
        sum += marks[i];
    }
    double average = static_cast<double>(sum) / numStudents;
    cout << "Average mark: " << average << endl;

    // Calculate highest mark
    int highest = marks[0];
    for (int i = 1; i < numStudents; ++i) {
        if (marks[i] > highest) {
            highest = marks[i];
        }
    }
    cout << "Highest mark: " << highest << endl;

    // Calculate number of students scoring less than 40
    int lessThan40 = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (marks[i] < 40) {
            lessThan40++;
        }
    }
    cout << "Number of students scoring less than 40: " << lessThan40 << endl;

    // Calculate histogram
    int histogram[11] = {0}; // to store counts for each range
    for (int i = 0; i < numStudents; ++i) {
        int range = marks[i] / 10;
        histogram[range]++;
    }
    cout << "Histogram (0-100):" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << i * 10 << "-" << (i * 10) + 9 << ": " << histogram[i] << " students" << endl;
    }
    cout << "100: " << histogram[10] << " students" << endl;
}

int main() {
    int marks[MAX_STUDENTS];
    int numStudents = 0;

    cout << "Enter marks (0-100) for students. Enter a negative number to stop: " << endl;
    int mark;
    while (cin >> mark && mark >= 0 && numStudents < MAX_STUDENTS) {
        marks[numStudents] = mark;
        numStudents++;
    }

    if (numStudents == 0) {
        cout << "No marks entered." << endl;
        return 1;
    }

    calculateStatistics(marks, numStudents);

    return 0;
}

/*
Write a program that takes an array of integers of size 'n' as input from the user. Write separate
functions for the following operations
1. Search: Take an element as input from the user. If the element is present in the array return
the index of the element. Otherwise return -1
2. Delete from a particular position: Take the index of the array as input from the user. The
function should delete the element at that position from the array. It should retain the
ordering of elements in the array.
3. Delete a particular element: Take an integer as input from the user. If the element is
present, delete that element from the array. It should retain the ordering of elements in the
array.
4. Inserting an element at the end - Take an integer as input from the user. Insert the
element at the end of the array.
5. Inserting an element at a particular position - Take an integer and position as inputs from
the user. Insert the element at the appropriate position in the array.
*/


#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to delete an element at a particular index
void deleteAtIndex(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index." << endl;
        return;
    }

    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    size--; // Decrease the size of the array
}

// Function to delete a particular element from the array
void deleteElement(int arr[], int& size, int element) {
    int index = searchElement(arr, size, element);
    if (index != -1) {
        deleteAtIndex(arr, size, index);
    } else {
        cout << "Element not found." << endl;
    }
}

// Function to insert an element at the end of the array
void insertEnd(int arr[], int& size, int element) {
    if (size >= MAX_SIZE) {
        cout << "Array is full, cannot insert." << endl;
        return;
    }
    arr[size] = element;
    size++;
}

// Function to insert an element at a particular position in the array
void insertAtIndex(int arr[], int& size, int element, int index) {
    if (size >= MAX_SIZE || index < 0 || index > size) {
        cout << "Invalid index or array is full, cannot insert." << endl;
        return;
    }

    for (int i = size - 1; i >= index; --i) {
        arr[i + 1] = arr[i]; // Shift elements to the right
    }
    arr[index] = element;
    size++;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter " << size << " integers for the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Array before operations: ";
    printArray(arr, size);

    // Example usage of operations
    int element, index;

    cout << "Enter an element to search: ";
    cin >> element;
    int foundIndex = searchElement(arr, size, element);
    if (foundIndex != -1) {
        cout << "Element found at index: " << foundIndex << endl;
    } else {
        cout << "Element not found." << endl;
    }

    cout << "Enter an index to delete: ";
    cin >> index;
    deleteAtIndex(arr, size, index);
    cout << "Array after deleting at index: ";
    printArray(arr, size);

    cout << "Enter an element to delete: ";
    cin >> element;
    deleteElement(arr, size, element);
    cout << "Array after deleting element: ";
    printArray(arr, size);

    cout << "Enter an element to insert at the end: ";
    cin >> element;
    insertEnd(arr, size, element);
    cout << "Array after inserting at the end: ";
    printArray(arr, size);

    cout << "Enter an element and position to insert: ";
    cin >> element >> index;
    insertAtIndex(arr, size, element, index);
    cout << "Array after inserting at index: ";
    printArray(arr, size);
}

/*
Write a program that takes an array of integers of size 'n' as input from the user. Write separate
functions for the following operations
1. Search: Take an element as input from the user. If the element is present in the array return
the index of the element. Otherwise return -1
2. Delete from a particular position: Take the index of the array as input from the user. The
function should delete the element at that position from the array. It should retain the
ordering of elements in the array.
3. Delete a particular element: Take an integer as input from the user. If the element is
present, delete that element from the array. It should retain the ordering of elements in the
array.
4. Inserting an element at the end - Take an integer as input from the user. Insert the
element at the end of the array.
5. Inserting an element at a particular position - Take an integer and position as inputs from
the user. Insert the element at the appropriate position in the array.
*/
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to delete an element at a particular index
void deleteAtIndex(int arr[], int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index." << endl;
        return;
    }

    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    size--; // Decrease the size of the array
}

// Function to delete a particular element from the array
void deleteElement(int arr[], int& size, int element) {
    int index = searchElement(arr, size, element);
    if (index != -1) {
        deleteAtIndex(arr, size, index);
    } else {
        cout << "Element not found." << endl;
    }
}

// Function to insert an element at the end of the array
void insertEnd(int arr[], int& size, int element) {
    if (size >= MAX_SIZE) {
        cout << "Array is full, cannot insert." << endl;
        return;
    }
    arr[size] = element;
    size++;
}

// Function to insert an element at a particular position in the array
void insertAtIndex(int arr[], int& size, int element, int index) {
    if (size >= MAX_SIZE || index < 0 || index > size) {
        cout << "Invalid index or array is full, cannot insert." << endl;
        return;
    }

    for (int i = size - 1; i >= index; --i) {
        arr[i + 1] = arr[i]; // Shift elements to the right
    }
    arr[index] = element;
    size++;
}

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[MAX_SIZE];
    cout << "Enter " << n << " integers for the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Array before operations: ";
    printArray(arr, n);

    int choice, element, index;

    while (true) {
        cout << "Choose an operation:\n"
             << "1. Search an element\n"
             << "2. Delete from a particular position\n"
             << "3. Delete a particular element\n"
             << "4. Insert an element at the end\n"
             << "5. Insert an element at a particular position\n"
             << "6. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an element to search: ";
                cin >> element;
                index = searchElement(arr, n, element);
                if (index != -1) {
                    cout << "Element found at index: " << index << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;

            case 2:
                cout << "Enter an index to delete: ";
                cin >> index;
                deleteAtIndex(arr, n, index);
                cout << "Array after deleting at index: ";
                printArray(arr, n);
                break;

            case 3:
                cout << "Enter an element to delete: ";
                cin >> element;
                deleteElement(arr, n, element);
                cout << "Array after deleting element: ";
                printArray(arr, n);
                break;

            case 4:
                cout << "Enter an element to insert at the end: ";
                cin >> element;
                insertEnd(arr, n, element);
                cout << "Array after inserting at the end: ";
                printArray(arr, n);
                break;

            case 5:
                cout << "Enter an element and position to insert: ";
                cin >> element >> index;
                insertAtIndex(arr, n, element, index);
                cout << "Array after inserting at index: ";
                printArray(arr, n);
                break;

            case 6:
                cout << "Exiting program...";
                return 0;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    }
}

//2D ARRAYS
//Reading a 2 D array as input
int a[3][3];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++) {
cin>>a[i][j];
}
}
//Passing Two-Dimensional Arrays
const int COLUMNS = 3;
int function1(int table[][COLUMNS], int row) {
int s = 0;
for (int j = 0; j < COLUMNS; j++) {
s= s + table[row][j];
}
return s;
}
//Point to note - A two-dimensional array parameter must have a 
//fixed number of columns.

/*
A theater seating chart is implemented as a two-dimensional array of ticket prices,
like this:
10 10 10 10 10 10 10 10 10 10
10 10 10 10 10 10 10 10 10 10
10 10 10 10 10 10 10 10 10 10
10 10 20 20 20 20 20 20 10 10
10 10 20 20 20 20 20 20 10 10
10 10 20 20 20 20 20 20 10 10
20 20 30 30 40 40 30 30 20 20
20 30 30 40 50 50 40 30 30 20
30 40 50 50 50 50 50 50 40 30
Initialize the above 2 dimensional array in a variable - theater_seats.
Write a program for the theater owner to track seat occupancy and sales for a given day.
The theater owner can ask the user to pick either a seat or a price. Mark sold seats by changing
the price to 0.
When a user specifies a seat, make sure it is available.
When a user specifies a price, find any seat with that price.
When the theater owner specifies -1, that indicates that the theater is closed for the day.
Maintain the total sales in a variable total_sales, and finally print it.
*/

#include <iostream>
using namespace std;

int pick_seat(int theater[][10], int user_row, int user_col) {
  
}

int pick_price(int theater[][10], int price) {
  
}
int main() {
  int theater[9][10] = {{10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
                        {10, 10, 20, 20, 20, 20, 20, 20, 10, 10},
                        {10, 10, 20, 20, 20, 20, 20, 20, 10, 10},
                        {10, 10, 20, 20, 20, 20, 20, 20, 10, 10},
                        {20, 20, 30, 30, 40, 40, 30, 30, 20, 20},
                        {20, 30, 30, 40, 50, 50, 40, 30, 30, 20},
                        {30, 40, 50, 50, 50, 50, 50, 50, 40, 30}};
  int sale = 0;

  int choice;
  cout << "1. Pick a seat\n 2. Pick a row and col\n Enter -1 to exit";
  cin >> choice;

  while (choice != -1) {
    if (choice == 1) {
      // Option - User picks a seat
      int row, col;
      cout << "Enter the row ";
      cin >> row;
      cout << "Enter the column";
      cin >> col;
      int result = pick_seat(theater, row, col);
      if (result != -1) {
        sale = sale + result;
      } else {
        cout << "Ticket not available. Please try again";
      }
    } else if (choice == 2) {
      // Option - User picks a price;
      int price;
      cout << "Enter a price: ";
      cin>>price;
      int result = pick_price(theater, price);
      if (result != -1) {
        sale = sale + result;
      } else {
        cout << "Ticket with price " << price
             << " not available. Please try again";
      }
    }
    cout << "1. Pick a seat\n 2. Pick a row and col\n Enter -1 to exit";
    cin >> choice;
  }
  cout<<"Total sales = "<<sale<<endl;
}
/*
Write array functions that carry out the following tasks for an array of integers. You can
directly initialize the array
a. Replace each element except the first and last by the larger of its two neighbors.
b. Remove the middle element if the array length is odd, or the middle two elements if the
length is even.
c. Move all even elements to the front, otherwise preserving the order of the elements.
d. Return true if all elements of the array are identical.
e. Return the second-largest element in the array.
f. Return true if the array is currently sorted in increasing order.
*/

//a

void replaceNeighbors(int arr[], int size) {
    if (size < 3) {
        return;
    }
    for (int i = 1; i < size - 1; ++i) {
        int larger = std::max(arr[i - 1], arr[i + 1]);
        arr[i] = larger;
    }
}
//b

void removeMiddle(int arr[], int& size) {
    if (size == 0 || size == 1) {
        return;
    }
    int middle = size / 2;
    if (size % 2 == 0) {
        for (int i = middle; i < size - 2; ++i) {
            arr[i] = arr[i + 2];
        }
        size -= 2;
    } else {
        for (int i = middle; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size -= 1;
    }
}
//c
void moveEvenToFront(int arr[], int size) {
    int left = 0, right = size - 1;
    while (left < right) {
        while (arr[left] % 2 == 0 && left < right) {
            left++;
        }
        while (arr[right] % 2 != 0 && left < right) {
            right--;
        }
        if (left < right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}
//d
bool allIdentical(int arr[], int size) {
    if (size <= 1) {
        return true;
    }
    for (int i = 1; i < size; ++i) {
        if (arr[i] != arr[0]) {
            return false;
        }
    }
    return true;
}
//e
int secondLargest(int arr[], int size) {
    if (size < 2) {
        return -1; // Not enough elements
    }
    int largest = arr[0], second_largest = INT_MIN;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
    return second_largest != INT_MIN ? second_largest : -1; // No second largest found
}
//f
bool isSorted(int arr[], int size) {
    if (size <= 1) {
        return true;
    }
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

/*
Write a function bool equals(int a[], int a_size, int b[], int b_size) that checks
whether two arrays have the same elements in the same order.
*/
bool equals(int a[], int a_size, int b[], int b_size) {
    if (a_size != b_size) {
        return false;
    }

    for (int i = 0; i < a_size; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}
/*
Write a function bool same_set(int a[], int a_size, int b[], int b_size)
that checks whether two vectors have the same elements in some order, ignoring duplicates.
For example, the two arrays
1 4 9 16 9 7 4 9 11
and
11 11 7 9 16 4 1
would be considered identical. You will probably need one or more helper functions
*/

bool same_set(int a[], int a_size, int b[], int b_size) {
    // Sort the arrays
    std::sort(a, a + a_size);
    std::sort(b, b + b_size);

    // Remove duplicates from sorted arrays
    a_size = std::unique(a, a + a_size) - a;
    b_size = std::unique(b, b + b_size) - b;

    if (a_size != b_size) {
        return false;
    }

    for (int i = 0; i < a_size; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

/*
7. Given the definitions
Assume the starting address of primes[0] is 0, and an int occupies 4 bytes
What is the value of
a. primes[1] 
b. primes + 1 
c. *(primes + 1) 
d. p+1
*/
int primes[] = { 2, 3, 5, 7, 11, 13 };
int* p = primes + 3;

/*

a. primes[1]: 
This represents the value at index 1 in the array `primes`, which is `3`.

b. primes + 1`\: 
This represents the memory address of the element at index 1 in the `primes` array. 
Assuming an `int` occupies 4 bytes, the address would be `0` (starting address) + `1 * sizeof(int)`, 
which is `4` bytes from the starting address.

c. *(primes + 1): 
This dereferences the memory address calculated above. 
It accesses the value stored at the memory address `4` bytes from the starting address of the `primes` array. 
This value is `3`.

d. p+1: This represents the memory address obtained by adding `1` to the pointer `p`, 
which points to `primes + 3`. Adding `1` to a pointer moves it forward by the size of the pointed data type (`int` in this case), 
so it points to the next `int` element in memory after `primes + 3`. Therefore, the address would be `primes + 3` + `1 * sizeof(int)`, 
which is `16` bytes from the starting address.
*/
