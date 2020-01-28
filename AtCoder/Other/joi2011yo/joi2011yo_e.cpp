#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int main() {
  int H, W, N;
  cin >> H >> W >> N;

  int sx, sy;
  vector<vector<char>> grid(H, vector<char>(W, ' '));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid.at(i).at(j);

      if (grid.at(i).at(j) == 'S') {
        sx = i;
        sy = j;
      }
    }
  }

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  vector<vector<int>> count(H, vector<int>(W, -1));
  queue<P> que;

  int result = 0;

  for (int target = 1; target <= N; target++) {
    // countの初期化
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        count.at(i).at(j) = -1;
      }
    }
    count.at(sx).at(sy) = 0;

    // queの初期化
    while (!que.empty()) que.pop();
    que.push(P(sx, sy));

    while (!que.empty()) {
      P pos = que.front();
      int x = pos.first;
      int y = pos.second;
      que.pop();

      bool next = false;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (grid.at(nx).at(ny) == 'X') continue;
        if (count.at(nx).at(ny) != -1) continue;

        count.at(nx).at(ny) = count.at(x).at(y) + 1;
        que.push(P(nx, ny));

        if (grid.at(nx).at(ny) - '0' == target) {
          result += count.at(nx).at(ny);
          sx = nx;
          sy = ny;
          next = true;
          break;
        }
      }
      if (next) {
        break;
      }
    }
  }

  cout << result << endl;

  return 0;
}
