#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
  int N;
  cin >> N;

  vector<int> a(N + 1, 0);
  for (int i = 2; i <= N; i++) {
    int x = i;
    int j = 2;
    while (j <= x) {
      if (x % j == 0) {
        a.at(j)++;
        x /= j;
      } else {
        j++;
      }
    }
  }

  ll ans = 1;
  for (int i = 2; i <= N; i++) {
    ans = ans * ((a.at(i) + 1) % mod) % mod;
  }

  cout << ans << endl;

  return 0;
}
