#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void input(vector<unsigned long long> &arr) {
  cin >> arr[0] >> arr[1];
  cin.ignore();
}

unsigned long long solve(vector<unsigned long long> &arr, bool &end) {
  unsigned long long temp;
  if (arr.at(0) > arr.at(1)) {
    temp = arr.at(0) - arr.at(1);
  } else {
    temp = arr.at(1) - arr.at(0);
  }
  if (temp == 0) {
    end = true;
  }
  return temp;
}

int main() {
  bool end = false;
  while (!end) {
    vector<unsigned long long> arr(2, 0);
    input(arr);
    unsigned long long temp = solve(arr, end);
    if (!end) {
      cout << temp << endl;
    }
  }
}