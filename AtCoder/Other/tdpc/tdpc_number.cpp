#include <bits/stdc++.h>
using namespace std;

int main() {
  long long D;
  string N;
  cin >> D >> N;

  int L = N.size();

  vector<vector<vector<long long>>> dp(L + 1, vector<vector<long long>>(2, vector<long long>(D, 0)));
  dp.at(0).at(0).at(0) = 1;

  for (int i = 0; i < L; i++) {
    int x = N[i] - '0';
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < D; k++) {
        for (int d = 0; d <= (j ? 9 : x); d++) {
          dp.at(i + 1).at(j || d < x).at((k + d) % D) += dp.at(i).at(j).at(k) % 1000000007;
        }
      }
    }
  }

  long long ans = (dp.at(L).at(0).at(0) + dp.at(L).at(1).at(0) - 1) % 1000000007; // 0の分を除く
  cout << ans << endl;

  return 0;
}
