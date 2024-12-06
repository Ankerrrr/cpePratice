#include <iostream>
#include <string>
#include <vector>

using namespace std;

int smellIndex = 0;

struct d {
  int a, b;
} moveDir[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

char dirName[4] = {'N', 'W', 'S', 'E'};

vector<int>
inputSpace() {
  vector<int> size(2, 0);
  cin >> size.at(0) >> size.at(1);
  return size;
}

void inputQ(int &x, int &y, int question[3]) {
  char H;
  int dir;

  cin >> H;

  switch (H) {
  case 'N': // 北
    dir = 0;
    break;
  case 'W': // 西
    dir = 1;
    break;
  case 'S': // 南
    dir = 2;
    break;
  case 'E': // 東
    dir = 3;
    break;
  default:
    throw "input Wrong direction";
  }

  question[0] = x;
  question[1] = y;
  question[2] = dir;
}

string inputComm() {
  string in;

  cin.ignore();
  getline(cin, in);

  return in;
}

void solve(const vector<int> &size, const int question[3], string command, vector<pair<int, int>> &smell) {
  int nowX, nowY, nowDir;
  int commandLen = command.length();
  nowX = question[0];
  nowY = question[1];
  nowDir = question[2];
  bool Lost;

  for (int i = 0; i < commandLen; i++) {

    int getDir = command[i];

    if (getDir == 'F') {
      nowX = nowX + moveDir[nowDir].a;
      nowY = nowY + moveDir[nowDir].b;

      for (int i = 0; i < smell.size(); i++) {
        if (nowX == smell.at(i).first && nowY == smell.at(i).second) {
          nowX = nowX - moveDir[nowDir].a;
          nowY = nowY - moveDir[nowDir].b;
          break;
        }
      }

      if (nowX > size.at(0) || nowY > size.at(1) || nowX < 0 || nowY < 0) {
        Lost = true;

        smell.at(smellIndex).first = nowX;
        smell.at(smellIndex).second = nowY;

        nowX = nowX - moveDir[nowDir].a;
        nowY = nowY - moveDir[nowDir].b;

        smellIndex++;
      }

      if (Lost == true) {
        cout << nowX << " " << nowY << " " << dirName[nowDir] << " LOST" << endl;
        break;
      }

    } else if (getDir == 'R') {
      if (nowDir < 1) {
        nowDir = 3;
      } else {
        nowDir--;
      }
    } else if (getDir == 'L') {
      if (nowDir > 2) {
        nowDir = 0;
      } else {
        nowDir++;
      }
    } else {
      throw "Enter Wrong Command";
    }
    // cout << nowX << ", " << nowY << ", " << dirName[nowDir] << command[i] << endl;
  }
  if (!Lost) {
    cout << nowX << " " << nowY << " " << dirName[nowDir] << endl;
  }
  Lost = false;
}

int main() {
  vector<int> size = inputSpace(); // input size
  vector<pair<int, int>> smell(128, {-1, -1});
  int x, y;

  while (cin >> x >> y) {

    int question[3];

    inputQ(x, y, question);
    string inputCommand = inputComm();

    solve(size, question, inputCommand, smell);
  }
}
