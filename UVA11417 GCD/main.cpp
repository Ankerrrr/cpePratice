#include <algorithm>
#include <iostream>

using namespace std;

int gcd(const int x, const int y) {
  int minNumber = min(x, y);
  int record;

  for (int i = 1; i <= minNumber; i++) {
    if (x % i == 0 && y % i == 0) {
      record = i;
    }
  }
  return record;
}

void inp(int &x) {
  cin >> x;
}

int solve(int &x) {
  int G = 0;
  for (int i = 1; i < x; i++)
    for (int j = i + 1; j <= x; j++) {
      G += gcd(i, j);
    }
  return G;
}

int main() {
  while (1) {
    int x;
    inp(x);
    if (x == 0) {
      break;
    }
    cout << solve(x) << endl;
  }
  return 0;
}