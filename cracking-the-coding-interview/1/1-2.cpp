#include <bits/stdc++.h>
using namespace std;

bool isRearranged(string x, string y) {
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  return x == y;
}

int main() {
  string x, y;
  cin >> x >> y;
  string ans = isRearranged(x, y) ? "true" : "false";
  cout << ans << endl;
  return 0;
}