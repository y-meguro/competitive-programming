#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h.at(i);
  }

  vector<int> dp(N, INF);
  dp.at(0) = 0;
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= K; j++) {
      if (i - j < 0) break;
      dp.at(i) = min(dp.at(i), dp.at(i - j) + abs(h.at(i) - h.at(i - j)));
    }
  }

  cout << dp.at(N - 1) << endl;

  return 0;
}
