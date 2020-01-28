#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> x(N);
  for (int i = 0; i < N; i++) {
    cin >> x.at(i);
  }

  int ans = INT_MAX;
  for (int i = 0; i <= N - K; i++) {
    int d = min(abs(x.at(i)), abs(x.at(i + K - 1)));
    d += x.at(i + K - 1) - x.at(i);
    if (ans > d) ans = d;
  }

  cout << ans << endl;

  return 0;
}
