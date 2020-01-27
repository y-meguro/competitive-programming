#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;

  priority_queue<ll> q;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ll A;
    cin >> A;

    q.push(A);
    ans += A;
  }

  while (M > 0) {
    ll x = q.top();
    q.pop();

    q.push(x - (x + 1) / 2);
    ans -= (x + 1) / 2;
    M--;
  }

  cout << ans << endl;

  return 0;
}
