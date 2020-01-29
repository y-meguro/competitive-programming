#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
  int H, N;
  cin >> H >> N;

  vector<int> A(N), B(N);
  int minA = INF;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
    if (minA > A.at(i)) minA = A.at(i);
  }

  vector<int> dp(H + 1, INF);
  dp.at(0) = 0;
  for(int i = 0; i < N; i++) {
    for(int k = 0; k <= H; k++) {
      if (dp.at(k) == INF) continue;
      dp.at(min(k + A.at(i), H)) = min(dp.at(min(k + A.at(i), H)), dp.at(k) + B.at(i));
    }
  }
  cout << dp.at(H) << endl;
  return 0;
}