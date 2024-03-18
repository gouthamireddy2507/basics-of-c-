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