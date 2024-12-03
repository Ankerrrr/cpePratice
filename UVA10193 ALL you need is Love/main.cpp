#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int GCD(const int x, const int y) {
  int minNumber = min(x, y);

  int record = 1;
  for (int i = 1; i <= minNumber; i++) {
    if ((x % i == 0) && (y % i == 0)) {
      record = i;
    }
  }

  return record;
}

void inp(string &a, string &b) {
  cin >> a;
  cin >> b;
}

int changeToDec(string &a) {
  int total = 0;
  int index = 0;

  for (int i = a.length() - 1; i >= 0; i--) {
    if (index == 0) {
      total += a[i] - '0'; // cant pow(2,0)
    } else {
      total += pow(2, index) * (a[i] - '0');
    }
    index++;
  }

  return total;
}

bool solve() {
  string a, b;
  inp(a, b);

  int Dec_a;
  int Dec_b;
  Dec_a = changeToDec(a);
  Dec_b = changeToDec(b);

  if (GCD(Dec_a, Dec_b) > 1) {
    return true;
  }
  return false;
}

int main() {
  int n;
  int Case = 1;
  cin >> n;

  while (n > 0) {
    if (solve()) {
      cout << "Pair #" << Case << ": All you need is love!" << endl;
    } else {
      cout << "Pair #" << Case << ": Love is not all you need!" << endl;
    }
    Case++;
    n--;
  }
}