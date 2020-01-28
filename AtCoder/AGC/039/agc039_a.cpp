#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S;
  ll K;
  cin >> S >> K;

  ll ans = 0;
  int tmp = 1;
  for (int i = 1; i < S.size(); i++) {
    if (S[i] == S[i - 1]) {
      tmp++;
    } else {
      ans += tmp / 2;
      tmp = 1;
    }
  }
  ans += tmp / 2;

  if (S[0] == S[S.size() - 1]) {
    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
      if (S[i] == S[0]) cnt++;
      else break;
    }

    int cnt2 = 0;
    for (int i = S.size() - 1; i >= 0; i--) {
      if (S[i] == S[0]) cnt2++;
      else break;
    }

    if (cnt == S.size()) {
      cout << S.size() * K / 2 << endl;
    } else if (cnt % 2 == 0 || cnt2 % 2 == 0) {
      cout << ans * K << endl;
    } else {
      cout << (ans + 1) * K - 1 << endl;
    }
  } else {
    cout << ans * K << endl;
  }

  return 0;
}
