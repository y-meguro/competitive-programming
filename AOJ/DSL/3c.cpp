#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<ll> a(N), x(Q);
  rep(i, N) cin >> a.at(i);
  rep(i, Q) cin >> x.at(i);

  rep(i, Q) {
    ll target = x.at(i);
    ll res = 0;
    int right = 0;
    ll sum = 0;
    for (int left = 0; left < N; left++) {
      while (right < N && sum + a.at(right) <= target) {
        sum += a.at(right);
        right++;
      }
      res += right - left;

      if (right == left) {
        right++;
      } else {
        sum -= a.at(left);
      }
    }
    cout << res << endl;
  }
  return 0;
}