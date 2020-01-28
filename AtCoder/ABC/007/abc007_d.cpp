#include <bits/stdc++.h>
using namespace std;

long long solve(string S) {
  int L = S.size();
  vector<vector<vector<long long>>> dp(20, vector<vector<long long>>(2, vector<long long>(2, 0)));
  dp.at(0).at(0).at(0) = 1;

  for (int i = 0; i < L; i++) {
    int D = S[i] - '0';
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int d = 0; d <= (j ? 9 : D); d++) {
          dp.at(i + 1).at(j || d < D).at(k || d == 4 || d == 9) += dp.at(i).at(j).at(k);
        }
      }
    }
  }
  return dp.at(L).at(0).at(1) + dp.at(L).at(1).at(1);
}

int main() {
  long long A, B;
  cin >> A >> B;
  long long ans = solve(to_string(B)) - solve(to_string(A - 1));
  cout << ans << endl;
  return 0;
}
