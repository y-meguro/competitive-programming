#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  int n = S.size() + 1;
  vector<ll> a(n, 0);
  ll cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (S[i] == '>') {
      a.at(i + 1) = cnt;
      cnt++;
      a.at(i) = cnt;
    } else {
      cnt = 0;
    }
  }
  if (cnt != 0) a.at(0) = cnt;

  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (S[i] == '<') {
      cnt++;
      a.at(i + 1) = max(a.at(i + 1), cnt);
    } else {
      cnt = 0;
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a.at(i);
  }

  cout << ans << endl;

  return 0;
}
