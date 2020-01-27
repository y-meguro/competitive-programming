#include <bits/stdc++.h>
using namespace std;

int main() {
  int L, R;
  cin >> L >> R;

  if (L / 2019 < R / 2019) {
    cout << 0 << endl;
    return 0;
  }

  int x = L % 2019;
  int y = R % 2019;
  int ans = 2019;
  for (int i = x; i < y; i++) {
    for (int j = x + 1; j <= y; j++) {
      ans = min(ans, i * j % 2019);
    }
  }

  cout << ans << endl;

  return 0;
}
