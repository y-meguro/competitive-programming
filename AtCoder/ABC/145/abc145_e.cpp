#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, T;
  cin >> N >> T;

  vector<int> A(N + 1, 0), B(N + 1, 0);
  rep(i, N) {
    cin >> A.at(i + 1) >> B.at(i + 1);
  }

  vector<vector<int>> dp1(N + 2, vector<int>(T + 1, 0));
  vector<vector<int>> dp2(N + 2, vector<int>(T + 1, 0));
  for (int i = 1; i <= N; i++) {
    rep(j, T) {
      dp1.at(i).at(j) = dp1.at(i - 1).at(j);
      if (j >= A.at(i)) {
        dp1.at(i).at(j) = max(dp1.at(i).at(j), dp1.at(i - 1).at(j - A.at(i)) + B.at(i));
      }
    }
  }

  for (int i = N; i >= 1; i--) {
    rep(j, T) {
      dp2.at(i).at(j) = dp2.at(i + 1).at(j);
      if (j >= A.at(i)) {
        dp2.at(i).at(j) = max(dp2.at(i).at(j), dp2.at(i + 1).at(j - A.at(i)) + B.at(i));
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    rep(j, T) {
      ans = max(ans, dp1.at(i - 1).at(j) + dp2.at(i + 1).at(T - 1 - j) + B.at(i));
    }
  }
  cout << ans << endl;
  return 0;
}