#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;

  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  vector<ll> s(N + 1);
  s.at(0) = 0;
  for (int i = 0; i < N; i++) s.at(i + 1) = s.at(i) + A.at(i);
  for (int i = 0; i <= N; i++) s.at(i) = (s.at(i) - i) % K;

  map<ll, ll> m;
  ll ans = 0;
  for (int i = 0; i <= N; i++) {
    m[s.at(i)]++;
    if (i >= K) m[s.at(i - K)]--;
    ans += m[s.at(i)] - 1;
  }

  cout << ans << endl;

  return 0;
}
