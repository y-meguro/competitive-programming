#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

int main() {
  int N, M;
  cin >> N >> M;
  int N2 = pow(2, N);
  vector<int> dp(N2, INF);
  dp.at(0) = 0;

  rep(i, M) {
    int a, b;
    cin >> a >> b;

    int tmp = 0;
    rep(j, b) {
      int c;
      cin >> c;
      c--;
      tmp += 1 << c;
    }
    rep(j, N2) {
      if (dp.at(j) == INF) continue;
      dp.at(j | tmp) = min(dp.at(j | tmp), dp.at(j) + a);
    }
  }

  if (dp.at(N2 - 1) == INF) {
    cout << -1 << endl;
  } else {
    cout << dp.at(N2 - 1) << endl;
  }
  return 0;
}