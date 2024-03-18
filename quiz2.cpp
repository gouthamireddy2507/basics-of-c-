// Question 1
#include <iostream>
using namespace std;
void AdjacentDuplicates(int array[], int size) {
    bool found = false;
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] == array[i + 1]) {
            found = true;
            cout << array[i] << " ";
            while (i < size - 1 && array[i] == array[i + 1]) {
                i++;
            }
        }
    }

    if (!found) {
        cout << "No adjacent duplicates found.";
    }
}
int main() {
    // Initializing array: 4 3 3 4 5 5 6 6 2
    int array[] = {4, 3, 3, 4, 5, 5, 6, 6, 2};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Adjacent duplicates in the array: ";
    AdjacentDuplicates(array, size);
}
//Question2 
#include <iostream>
using namespace std;
int alternating_sum(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            sum += array[i];  
        } else {
            sum -= array[i]; 
        }
    }
    return sum;
}

int main() {
    int numbers[] = {1, 4, 9, 16, 9, 7, 4, 9, 11};
    int size = sizeof(numbers) / sizeof(numbers[0]);  
    int result = alternating_sum(numbers, size);
    cout << "Alternating sum: " <<result <<endl;
}
//Question 3

#include <iostream>

using namespace std;

int next_visitor(bool occupied[], int stalls);

void printstalls(bool occupied[], int stalls) {
  for (int x = 0; x < stalls; x++) {
    if (!occupied[x]) {
      cout << "_";
    } else {
      cout << "X";
    }
  }
  cout << endl;
}
int main() {
  int stalls = 10;
  bool occupied[] = {false, false, false, false, false,
                     false, false, false, false, false};
  for (int i = 1; i <= stalls; i++) {
    int next = next_visitor(occupied, stalls);
    cout << "Next visitor = " << next << endl;
    occupied[next] = true;
    // printing the stalls
    printstalls(occupied, stalls);
  }
}

int next_visitor(bool occupied[], int stalls) {
    int maxEmptyDistance = 0;  
    int currEmptyDistance = 0;
    int positiontobeoccupied = -1;  

    for (int i = 0; i < stalls; i++) {
        if (!occupied[i]) {
            currEmptyDistance++;
            if (i == stalls - 1 || occupied[i + 1]) {

                if (currEmptyDistance > maxEmptyDistance) {
                    maxEmptyDistance = currEmptyDistance;
                    positiontobeoccupied = i - currEmptyDistance / 2;
                }
                currEmptyDistance = 0;  
            }
        }
    }

    return positiontobeoccupied;
}