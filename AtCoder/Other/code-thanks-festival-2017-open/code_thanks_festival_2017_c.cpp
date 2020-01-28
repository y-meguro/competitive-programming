#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;

  priority_queue<pair<ll, ll>> q;
  for (int i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    q.push(make_pair(-a, b));
  }

  ll ans = 0;
  for (int i = 0; i < K; i++) {
    pair<ll, ll> p = q.top();
    q.pop();

    ans += -p.first;
    p.first -= p.second;
    q.push(p);
  }

  cout << ans << endl;

  return 0;
}
