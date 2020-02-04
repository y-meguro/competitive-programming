#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int mod = 1e9 + 7;

int main() {
  int N;
  cin >> N;

  vector<ll> C(N);
  rep(i, N) cin >> C.at(i);
  sort(C.begin(), C.end());

  ll ans = 0;
  rep(i, N) {
    ans += C.at(i) * (N - i + 1) % mod;
  }
  for (int i = 1; i < N; i++) {
    ans = ans * 4 % mod;
  }
  cout << ans << endl;
  return 0;
}