#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<char>> blocks(H, vector<char>(W));
  rep(i, H) {
    rep(j, W) {
      cin >> blocks.at(i).at(j);
    }
  }

  int ans = 0;
  for (int row = 0; row < (1 << H); row++) {
    for (int col = 0; col < (1 << W); col++) {
      int count = 0;
      for (int i = 0; i < H; i++) {
        if ((row >> i) & 1) continue;
        for (int j = 0; j < W; j++) {
          if ((col >> j) & 1) continue;
          if (blocks.at(i).at(j) == '#') count++;
        }
      }
      if (count == K) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}