#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &inp) {

  int i = inp.at(0);
  int j = inp.at(1);

  if (i > j) {
    swap(i, j);
  }

  int maxCount = 0;

  for (int g = i; g <= j; g++) {
    int n = g;

    int count = 1;
    while (n != 1) {
      count++;
      if (n % 2 == 1) {
        n = n * 3 + 1;
      } else {
        n /= 2;
      }
    }
    if (count > maxCount) {
      maxCount = count;
    }
  }

  return maxCount;
}

int main() {
  vector<int> inp(2, 0);

  while (cin >> inp.at(0) >> inp.at(1)) {
    int ans = solve(inp);
    cout << inp.at(0) << " " << inp.at(1) << " " << ans << endl;
  }

  return 0;
}
