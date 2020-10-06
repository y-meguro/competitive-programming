#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> numA(n + 1, 0), numT(n + 1, 0), numC(n + 1, 0), numG(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    numA.at(i) = numA.at(i - 1);
    numT.at(i) = numT.at(i - 1);
    numC.at(i) = numC.at(i - 1);
    numG.at(i) = numG.at(i - 1);

    if (s[i - 1] == 'A') numA.at(i)++;
    else if (s[i - 1] == 'T') numT.at(i)++;
    else if (s[i - 1] == 'C') numC.at(i)++;
    else numG.at(i)++;
  }

  int ans = 0;
  for (int i = 0; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      int a = numA.at(j) - numA.at(i);
      int t = numT.at(j) - numT.at(i);
      int c = numC.at(j) - numC.at(i);
      int g = numG.at(j) - numG.at(i);
      if (a == t && c == g) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}