#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) { // �ۭq sort ����
  if (a.second == b.second) {
    return a.first > b.first;
  }
  return a.second < b.second;
}

void inp(vector<pair<int, int>> &table, bool &end) { // �� vector
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
  sort(table.begin(), table.end(), comp); // �̥k���ƧǤ覡 greather<int>()�j��p ,�w�]�p��j
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

    vector<pair<int, int>> table(128); // pair���U�]�t first, second
    for (int i = 0; i < 128; i++) {    // pair����ϥ� (size, value)���覡��l�Ҧ���
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