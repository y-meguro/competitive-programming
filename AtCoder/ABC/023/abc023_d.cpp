#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
  ll N;
  cin >> N;
  vector<ll> H(N), S(N);
  rep(i, N) {
    cin >> H.at(i) >> S.at(i);
  }

  ll l = 0;
  ll r = 1e15;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    vector<int> x(N);
    bool isValid = true;
    rep(i, N) {
      if (mid < H.at(i)) {
        isValid = false;
        break;
      } else {
        x.at(min(N - 1, (mid - H.at(i)) / S.at(i)))++;
      }
    }
    if (!isValid) {
      l = mid;
      continue;
    }

    ll cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
      cnt += x.at(i);
      if (cnt < N - i) {
        isValid = false;
        break;
      }
    }
    if (isValid) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;
  return 0;
}