#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  double ans = 0;
  for (int i = n; i >= 1; i--) {
    int x = i;
    double p = 1;
    while (x < k) {
      x *= 2;
      p /= 2;
    }
    ans += p / n;
  }

  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}