#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> numA(n, 0), numT(n, 0), numC(n, 0), numG(n, 0);
  rep(i, n) {
    if (i != 0) {
      numA.at(i) = numA.at(i - 1);
      numT.at(i) = numT.at(i - 1);
      numC.at(i) = numC.at(i - 1);
      numG.at(i) = numG.at(i - 1);
    }

    if (s[i] == 'A') {
      if (i == 0) numA.at(i) = 1;
      else numA.at(i)++;
    } else if (s[i] == 'T') {
      if (i == 0) numT.at(i) = 1;
      else numT.at(i)++;
    } else if (s[i] == 'C') {
      if (i == 0) numC.at(i) = 1;
      else numC.at(i)++;
    } else {
      if (i == 0) numG.at(i) = 1;
      else numG.at(i)++;
    }
  }

  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int a = numA.at(j);
      int t = numT.at(j);
      int c = numC.at(j);
      int g = numG.at(j);

      if (i != 0) {
        a -= numA.at(i - 1);
        t -= numT.at(i - 1);
        c -= numC.at(i - 1);
        g -= numG.at(i - 1);
      }
      if (a == t && c == g) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}