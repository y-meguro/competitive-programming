#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;

  vector<double> p(N + 1, 0.0);
  for (int i = 1; i <= N; i++) {
    cin >> p.at(i);
  }

  vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0.0));
  dp.at(1).at(0) = 1 - p.at(1);
  dp.at(1).at(1) = p.at(1);

  for (int i = 2; i <= N; i++) {
    dp.at(i).at(0) = dp.at(i - 1).at(0) * (1 - p.at(i));
    for (int j = 1; j <= N; j++) {
      dp.at(i).at(j) = dp.at(i - 1).at(j - 1) * p.at(i) + dp.at(i - 1).at(j) * (1 - p.at(i));
    }
  }

  double ans = 0.0;
  for (int i = N/2 + 1; i <= N; i++) {
    ans += dp.at(N).at(i);
  }

  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}