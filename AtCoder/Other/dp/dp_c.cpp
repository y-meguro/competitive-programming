#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a(N), b(N), c(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i) >> b.at(i) >> c.at(i);
  }

  vector<vector<int>> dp(N, vector<int>(3, -1));
  dp.at(0) = {a.at(0), b.at(0), c.at(0)};
  for (int i = 1; i < N; i++) {
    dp.at(i).at(0) = a.at(i) + max(dp.at(i - 1).at(1), dp.at(i - 1).at(2));
    dp.at(i).at(1) = b.at(i) + max(dp.at(i - 1).at(0), dp.at(i - 1).at(2));
    dp.at(i).at(2) = c.at(i) + max(dp.at(i - 1).at(0), dp.at(i - 1).at(1));
  }

  int ans = max(dp.at(N - 1).at(0), dp.at(N - 1).at(1));
  ans = max(ans, dp.at(N - 1).at(2));

  cout << ans << endl;

  return 0;
}
