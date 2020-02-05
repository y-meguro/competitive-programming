#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll INF = 1e10;

int N;
vector<vector<ll>> dp;

void warshallFloyd() {
  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k).at(j));
      }
    }
  }
}

int main() {
  int M, R;
  cin >> N >> M >> R;
  dp.resize(N, vector<ll>(N, INF));

  vector<int> r(R);
  rep(i, R) {
    int x;
    cin >> x;
    x--;
    r.at(i) = x;
  }

  rep(i, M) {
    int A, B, C;
    cin >> A >> B >> C;
    A--; B--;

    dp.at(A).at(B) = C;
    dp.at(B).at(A) = C;
  }
  rep(i, N) dp.at(i).at(i) = 0;

  warshallFloyd();

  ll ans = INF;
  sort(r.begin(), r.end());
  do {
    ll tmp = 0;
    rep(i, (int)r.size() - 1) tmp += dp.at(r.at(i)).at(r.at(i + 1));
    ans = min(ans, tmp);
  } while (next_permutation(r.begin(), r.end()));

  cout << ans << endl;
  return 0;
}