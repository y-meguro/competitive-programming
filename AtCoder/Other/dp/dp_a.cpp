#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
  int N;
  cin >> N;

  vector<int> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h.at(i);
  }

  vector<int> dp(N, INF);
  dp.at(0) = 0;

  for (int i = 1; i < N; i++) {
    if (i >= 2) dp.at(i) = min(dp.at(i), dp.at(i - 2) + abs(h.at(i) - h.at(i - 2)));
    dp.at(i) = min(dp.at(i), dp.at(i - 1) + abs(h.at(i) - h.at(i - 1)));
  }

  cout << dp.at(N - 1) << endl;

  return 0;
}
