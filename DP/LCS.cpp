#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int ls = s.length();
  int lt = t.length();
  vector<vector<int>> dp(ls + 1, vector<int>(lt + 1, 0));

  for (int i = 0; i <= ls; i++) {
    for (int j = 0; j <= lt; j++) {
      if (i == 0 || j == 0) {
        dp.at(i).at(j) = 0;
        continue;
      }
      if (s[i - 1] == t[j - 1]) {
        dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
      } else {
        dp.at(i).at(j) = max(dp.at(i - 1).at(j), dp.at(i).at(j - 1));
      }
    }
  }

  int i = ls;
  int j = lt;
  string ans = "";

  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1]) {
      ans += s[i - 1];
      i--;
      j--;
    } else if (dp.at(i - 1).at(j) > dp.at(i).at(j - 1)) {
      i--;
    } else {
      j--;
    }
  }
  reverse(ans.begin(), ans.end());

  cout << ans << endl;

  return 0;
}
