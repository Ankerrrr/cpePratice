#include <iostream>
#include <vector>

using namespace std;

void Boring() {
  cout << "Boring!" << endl;
}

int main() {
  int a, b;
  while (cin >> a >> b) {
    if (b == 1) {
      Boring();
      continue;
    }
    vector<int> ans(0);
    bool isBoring = false;
    while (1) {
      if (!(a % b)) {
        ans.push_back(a);
        if (a == b) {
          ans.push_back(1);
          break;
        }
        a /= b;
      } else {
        isBoring = true;
        Boring();
        break;
      }
    }
    if (isBoring) {
      continue;
    }
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i];
      if (i != ans.size() - 1)
        cout << " ";
    }
    cout << endl;
  }
}