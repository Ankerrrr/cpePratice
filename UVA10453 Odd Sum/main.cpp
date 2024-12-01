#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &arr) {
  cin >> arr[0];
  cin >> arr[1];
}

int solve(vector<int> &arr) {
  int a = arr[0];
  int b = arr[1];

  int sum = 0;

  for (int i = a; i <= b; i++) {
    if (i % 2 == 1) {
      sum += i;
    }
  }
  return sum;
}

int main() {
  int count = 0;
  cin >> count;
  int caseCount = 1;
  while (count > 0) {
    vector<int> arr(2, 0);
    input(arr);
    cout << "Case " << caseCount << ": " << solve(arr) << endl;
    count--;
    caseCount++;
  }
}