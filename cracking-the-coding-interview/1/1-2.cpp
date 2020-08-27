#include <bits/stdc++.h>
using namespace std;

bool isRearranged(string x, string y) {
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  return x == y;
}

bool isRearranged2(string x, string y) {
  if (x.size() != y.size()) return false;

  vector<int> chars(26, 0);
  for (int i = 0; i < (int)x.size(); i++) {
    chars.at(x.at(i) - 'a')++;
  }
  for (int i = 0; i < (int)y.size(); i++) {
    chars.at(y.at(i) - 'a')--;
    if (chars.at(y.at(i) - 'a') < 0) return false;
  }
  return true;
}

int main() {
  string x, y;
  cin >> x >> y;
  string ans = isRearranged2(x, y) ? "true" : "false";
  cout << ans << endl;
  return 0;
}