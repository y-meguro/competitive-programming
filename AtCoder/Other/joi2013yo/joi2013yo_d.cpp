#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, N;
  cin >> D >> N;

  vector<int> T(D);
  for (int i = 0; i < D; i++) {
    cin >> T.at(i);
  }

  vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i) >> C.at(i);
  }

  vector<vector<int>> dp(D + 1, vector<int>(101, -1));
  dp.at(0).at(0) = 0;

  for (int i = 0; i < D; i++) {
    for (int p = 0; p <= 100; p++) {
      if (dp.at(i).at(p) == -1) continue;
      for (int q = 0; q < N; q++) {
        if (A.at(q) <= T.at(i) && T.at(i) <= B.at(q)) {
          if (i == 0) {
            dp.at(i + 1).at(C.at(q)) = 0;
          } else {
            int val = max(p, C.at(q)) - min(p, C.at(q));
            dp.at(i + 1).at(C.at(q)) = max(dp.at(i + 1).at(C.at(q)), dp.at(i).at(p) + val);
          }
        }
      }
    }
  }

  int max = 0;
  for (int i = 0; i <= 100; i++) {
    if (dp.at(D).at(i) > max) {
      max = dp.at(D).at(i);
    }
  }

  cout << max << endl;

  return 0;
}
