#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) { // 自訂 sort 條件
  if (a.second == b.second) {
    return a.first > b.first;
  }
  return a.second < b.second;
}

void inp(vector<pair<int, int>> &table, bool &end) { // 傳 vector
  string inp;
  getline(cin, inp);

  if (inp.length() == 0) {
    end = true;
  } else {
    for (int i = 0; i < inp.length(); i++) {
      table[(int)inp[i]].second++;
    }
  }
}

void printOut(vector<pair<int, int>> &table, bool &firstLine) {
  if (!firstLine) {
    cout << endl;
  } else {
    firstLine = false;
  }
  sort(table.begin(), table.end(), comp); // 最右邊放排序方式 greather<int>()大到小 ,預設小到大
  for (int i = 0; i < table.size(); i++) {
    if (table[i].second > 0) {
      cout << (int)table[i].first << " " << table[i].second << endl;
    }
  }
}

int main() {
  bool firstLine = true;
  while (1) {
    bool end = false;

    vector<pair<int, int>> table(128); // pair底下包含 first, second
    for (int i = 0; i < 128; i++) {    // pair不能使用 (size, value)的方式初始所有值
      table[i].first = i;
      table[i].second = 0;
    }

    inp(table, end);

    if (end) {
      break;
    }
    printOut(table, firstLine);
  }
  return 0;
}