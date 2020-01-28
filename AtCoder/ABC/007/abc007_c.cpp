#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, C;
  cin >> R >> C;

  int sx, sy, gx, gy;
  cin >> sy >> sx >> gy >> gx;
  sx--;
  sy--;
  gx--;
  gy--;

  vector<vector<char>> maze(R, vector<char>(C, ' '));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> maze.at(i).at(j);
    }
  }

  vector<vector<int>> count(R, vector<int>(C, -1));

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  queue<pair<int, int>> que;
  que.push(pair<int, int>(sy, sx));
  count.at(sy).at(sx) = 0;

  while(!que.empty()) {
    pair<int, int> pos = que.front();
    que.pop();

    if (pos.second == gx && pos.first == gy) {
      cout << count.at(pos.first).at(pos.second) << endl;
      break;
    }

    for (int i = 0; i < 4; i++) {
      int nx = pos.second + dx[i];
      int ny = pos.first + dy[i];

      if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
      if (maze.at(ny).at(nx) == '#') continue;
      if (count.at(ny).at(nx) != -1) continue;

      count.at(ny).at(nx) = count.at(pos.first).at(pos.second) + 1;
      que.push(pair<int, int>(ny, nx));
    }
  }

  return 0;
}
