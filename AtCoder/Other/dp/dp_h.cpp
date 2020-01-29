#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> G(H + 1, vector<char>(W + 1, '#'));
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> G.at(i).at(j);
    }
  }

  vector<vector<int>> dp(H + 1, vector<int>(W + 1, 0));
  dp.at(1).at(1) = 1;

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (G.at(i).at(j) == '#') continue;
      dp.at(i).at(j) += (dp.at(i - 1).at(j) + dp.at(i).at(j - 1)) % mod;
    }
  }

  cout << dp.at(H).at(W) << endl;
  return 0;
}