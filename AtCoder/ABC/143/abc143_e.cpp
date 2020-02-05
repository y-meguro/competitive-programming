#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll INF = 1e14;
const int INF2 = 1e9;

int main() {
  int N, M, L;
  cin >> N >> M >> L;

  vector<vector<ll>> dp(N, vector<ll>(N, INF));
  rep(i, M) {
    int A, B, C;
    cin >> A >> B >> C;
    A--; B--;

    dp.at(A).at(B) = C;
    dp.at(B).at(A) = C;
  }
  rep(i, N) dp.at(i).at(i) = 0;

  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k).at(j));
      }
    }
  }

  vector<vector<int>> fuel(N, vector<int>(N, INF2));
  rep(i, N) {
    rep(j, N) {
      if (dp.at(i).at(j) <= L) fuel.at(i).at(j) = 1;;
    }
  }
  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        fuel.at(i).at(j) = min(fuel.at(i).at(j), fuel.at(i).at(k) + fuel.at(k).at(j));
      }
    }
  }

  int Q;
  cin >> Q;

  rep(i, Q) {
    int s, t;
    cin >> s >> t;
    s--; t--;

    if (fuel.at(s).at(t) == INF2) {
      cout << -1 << endl;
    } else {
      cout << fuel.at(s).at(t) - 1 << endl; // 最初の補給は除く
    }
  }

  return 0;
}