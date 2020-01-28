#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<int> A(N), B(N), C(N);

  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) cin >> B.at(i);
  for (int i = 0; i < N; i++) cin >> C.at(i);

  sort(A.begin(), A.end());
  sort(C.begin(), C.end());

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    int key = B.at(i);
    ll x = lower_bound(A.begin(), A.end(), key) - A.begin();
    ll y = upper_bound(C.begin(), C.end(), key) - C.begin();
    ans += x * (N - y);
  }

  cout << ans << endl;

  return 0;
}
