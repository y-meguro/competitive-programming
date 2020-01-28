#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  int sx, sy, gx, gy;
  vector<vector<char>> maze(H, vector<char>(W, ' '));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> maze.at(i).at(j);

      if (maze.at(i).at(j) == 's') {
        sx = i;
        sy = j;
      }
    }
  }

  deque<pair<int, int>> deq;
  deq.push_front(make_pair(sx, sy));

  vector<vector<int>> count(H, vector<int>(W, -1));
  count.at(sx).at(sy) = 0;

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  while(!deq.empty()) {
    int x = deq.front().first;
    int y = deq.front().second;
    deq.pop_front();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
      if (count.at(nx).at(ny) != -1) continue;

      char next = maze.at(nx).at(ny);
      if (next == '.') {
        count.at(nx).at(ny) = count.at(x).at(y);
        deq.push_front(make_pair(nx, ny));
      } else if (next == '#') {
        count.at(nx).at(ny) = count.at(x).at(y) + 1;
        deq.push_back(make_pair(nx, ny));
      } else if (next == 'g') {
        if (count.at(x).at(y) <= 2) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
        return 0;
      }
    }
  }

  return 0;
}
