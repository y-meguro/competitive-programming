#include <bits/stdc++.h>
using namespace std;

int H, W;

void search(int x, int y, vector<vector<char>>& c, vector<vector<bool>>& reached) {
  if (x < 0 || x >= H || y < 0 || y >= W) return;
  if (c.at(x).at(y) == '#') return;
  if (reached.at(x).at(y)) return;

  reached.at(x).at(y) = true;
  search(x + 1, y, c, reached);
  search(x - 1, y, c, reached);
  search(x, y + 1, c, reached);
  search(x, y - 1, c, reached);
}

int main() {
  cin >> H >> W;

  vector<vector<char>> c(H, vector<char>(W, ' '));
  int sx, sy, gx, gy;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> c.at(i).at(j);
      if (c.at(i).at(j) == 's') {
        sx = i;
        sy = j;
      } else if (c.at(i).at(j) == 'g') {
        gx = i;
        gy = j;
      }
    }
  }

  vector<vector<bool>> reached(H, vector<bool>(W, false));
  search(sx, sy, c, reached);

  if (reached.at(gx).at(gy)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
