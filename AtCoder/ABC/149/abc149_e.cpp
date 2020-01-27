#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());

  // M番目の Ax + Ay の値を求める
  ll low = 0;
  ll high = 1e10;
  while (high - low > 1) {
    ll mid = (low + high) / 2;
    ll num = 0;
    for (int i = 0; i < N; i++) {
      num += A.end() - lower_bound(A.begin(), A.end(), mid - A.at(i));
    }
    if (num >= M) {
      low = mid;
    } else {
      high = mid;
    }
  }

  // 累積和の計算
  vector<ll> s(N + 1, 0);
  for (int i = N - 1; i >= 0; i--) {
    s.at(i) = s.at(i + 1) + A.at(i);
  }

  ll ans = 0;
  ll cnt = 0;
  for (int i = 0; i < N; i++) {
    int x = upper_bound(A.begin(), A.end(), low - A.at(i)) - A.begin(); // 合計が low になるものは別で計算
    ans += (N - x) * A.at(i) + s.at(x);
    cnt += N - x;
  }
  ans += low * (M - cnt); // 合計が low になるものを加算

  cout << ans << endl;

  return 0;
}
