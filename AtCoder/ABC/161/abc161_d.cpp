#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k;
  cin >> k;

  queue<ll> q;
  for (int i = 1; i <= 9; i++) q.push(i);
  ll x;
  while (k != 0) {
    x = q.front();
    q.pop();
    k--;

    for (int j = -1; j <= 1; j++) {
      int d = x % 10 + j;
      if (d < 0 || d > 9) continue;
      q.push(x * 10 + d);
    }
  }

  cout << x << endl;
  return 0;
}