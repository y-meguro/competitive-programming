#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> A(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
    }
  }

  vector<vector<int>> B(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> B.at(i).at(j);
    }
  }

  vector<vector<vector<bool>>> DP(H, vector<vector<bool>>(W, vector<bool>(12801, false)));
  DP.at(0).at(0).at(abs(A.at(0).at(0) - B.at(0).at(0))) = true;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int p = abs(A.at(i).at(j) - B.at(i).at(j));
      for (int k = 0; k <= 12800; k++) {
        bool c1 = i > 0 ? DP.at(i - 1).at(j).at(k) : false;
        bool c2 = j > 0 ? DP.at(i).at(j - 1).at(k) : false;
        if (c1 || c2) {
          DP.at(i).at(j).at(k + p) = true;
          DP.at(i).at(j).at(abs(k - p)) = true;
        }
      }
    }
  }

  int ans;
  for (int i = 0; i <= 12800; i++) {
    if (DP.at(H - 1).at(W - 1).at(i)) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
