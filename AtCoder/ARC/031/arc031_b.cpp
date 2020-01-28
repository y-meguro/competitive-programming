#include <bits/stdc++.h>
using namespace std;

void explore(int x, int y, vector<vector<char>>& area, vector<vector<bool>>& reached) {
  if (x < 0 || x >= 10 || y < 0 || y >= 10) return;
  if (area.at(x).at(y) == 'x') return;
  if (reached.at(x).at(y)) return;

  reached.at(x).at(y) = true;

  explore(x + 1, y, area, reached);
  explore(x - 1, y, area, reached);
  explore(x, y + 1, area, reached);
  explore(x, y - 1, area, reached);
}

int main() {
  vector<vector<char>> area(10, vector<char>(10, ' '));

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> area.at(i).at(j);
    }
  }

  bool check = false;
  // 陸地に変える場所は全パターンを調べる
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      vector<vector<char>> newArea = area;
      if (newArea.at(i).at(j) == 'x') {
        newArea.at(i).at(j) = 'o';

        // 1つの島にできるかチェック
        vector<vector<bool>> reached(10, vector<bool>(10, false));
        explore(i, j, newArea, reached);

        bool isOne = true;
        for (int k = 0; k < 10; k++) {
          for (int l = 0; l < 10; l++) {
            if (newArea.at(k).at(l) == 'o' && !reached.at(k).at(l)) {
              isOne = false;
            }
          }
        }
        if (isOne) {
          check = true;
        }
      }
    }
  }

  if (check) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
