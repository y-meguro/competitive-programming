#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  int black_num = 0;
  vector<vector<char>> maze(H, vector<char>(W, ' '));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> maze.at(i).at(j);
      if (maze.at(i).at(j) == '#') black_num++;
    }
  }

  vector<vector<int>> count(H, vector<int>(W, -1));
  count.at(0).at(0) = 1;

  queue<pair<int, int>> que;
  que.push(pair<int, int>(0, 0));

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  while(!que.empty()) {
    pair<int, int> pos = que.front();
    que.pop();

    if (pos.first == H - 1 && pos.second == W - 1) {
      cout << H * W - black_num - count.at(pos.first).at(pos.second) << endl;
      return 0;
    }

    for (int i = 0; i < 4; i++) {
      int nx = pos.first + dx[i];
      int ny = pos.second + dy[i];

      if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
      if (maze.at(nx).at(ny) == '#') continue;
      if (count.at(nx).at(ny) != -1) continue;

      count.at(nx).at(ny) = count.at(pos.first).at(pos.second) + 1;
      que.push(pair<int, int>(nx, ny));
    }
  }

  cout << -1 << endl;
  return 0;
}
