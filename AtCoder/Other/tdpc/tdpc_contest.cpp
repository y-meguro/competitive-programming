#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int p[N];
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }

  vector<bool> dp(10001, false);
  dp.at(0) = true;

  for (int i = 0; i < N; i++) {
    for (int j = 10000; j >= 0; j--) {
      if (dp.at(j)) {
        dp.at(j + p[i]) = true;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= 10000; i++) {
    if (dp.at(i)) ans++;
  }

  cout << ans << endl;

  return 0;
}
