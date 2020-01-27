#include <bits/stdc++.h>
using namespace std;

int main() {
  long double a, b, x;
  cin >> a >> b >> x;

  long double ans;
  if (a * a * b / 2.0 > x) {
    ans = atan(a * b * b / (2 * x));
  } else {
    ans = atan(2 * (a * a * b - x) / (a * a * a));
  }

  cout << fixed << setprecision(10) << ans * 180 / M_PI << endl;

  return 0;
}
