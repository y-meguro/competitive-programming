#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }

  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < N - 1; i++) {
    if (H.at(i) >= H.at(i + 1)) {
      cnt++;
      if (cnt > ans) ans = cnt;
    } else {
      cnt = 0;
    }
  }

  cout << ans << endl;

  return 0;
}
