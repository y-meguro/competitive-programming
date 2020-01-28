#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  queue<pair<int, int>> que;
  vector<vector<int>> count(H, vector<int>(W, -1));

  vector<vector<char>> maze(H, vector<char>(W, ' '));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> maze.at(i).at(j);
      if (maze.at(i).at(j) == '#') {
        que.push(make_pair(i, j));
        count.at(i).at(j) = 0;
      }
    }
  }

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  int result = 0;

  while (!que.empty()) {
    pair<int, int> pos = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int nx = pos.first + dx[i];
      int ny = pos.second + dy[i];

      if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
      if (maze.at(nx).at(ny) == '#') continue;
      if (count.at(nx).at(ny) != -1) continue;

      count.at(nx).at(ny) = count.at(pos.first).at(pos.second) + 1;
      result = max(result, count.at(nx).at(ny));
      que.push(make_pair(nx, ny));
    }
  }

  cout << result << endl;

  return 0;
}
