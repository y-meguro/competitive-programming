#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
  }
  sort(L.begin(), L.end());

  int ans = 0;
  for (int i = 0; i < N - 2; i++) {
    for (int j = i + 1; j < N - 1; j++) {
      int key = L.at(i) + L.at(j);
      int k = lower_bound(L.begin(), L.end(), key) - L.begin();
      ans += k - j - 1;
    }
  }

  cout << ans << endl;

  return 0;
}
