#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, N, K;
  cin >> W >> N >> K;

  int A[N], B[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  vector<vector<int>> dp(K + 1, vector<int>(W + 1, -1));
  dp.at(0).at(0) = 0;

  for (int i = 0; i < N; i++) {
    for (int x = K; x >= 0; x--) {
      for (int y = W; y >= 0; y--) {
        if (x + 1 > K || y + A[i] > W || dp.at(x).at(y) == -1) continue;
        dp.at(x + 1).at(y + A[i]) = max(dp.at(x + 1).at(y + A[i]), dp.at(x).at(y) + B[i]);
      }
    }
  }

  int max = 0;
  for (int x = 0; x <= K; x++) {
    for (int y = 0; y <= W; y++) {
      if (dp.at(x).at(y) > max) {
        max = dp.at(x).at(y);
      }
    }
  }

  cout << max << endl;

  return 0;
}
