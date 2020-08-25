#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool isUniqueChars(string s) {
  int n = s.size();
  if (n > 128) return false;
  vector<bool> dic(128, false);
  for (int i = 0; i < n; i++) {
    char c = s.at(i);
    if (dic.at(c - 'a')) {
      return false;
    } else {
      dic.at(c - 'a') = true;
    }
  }
  return true;
}

int main() {
  string s;
  cin >> s;
  string ans = isUniqueChars(s) ? "true" : "false";
  cout << ans << endl;
  return 0;
}