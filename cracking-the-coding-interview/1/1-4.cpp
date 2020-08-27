#include <bits/stdc++.h>
using namespace std;

string toLower(string s) {
  string res = "";
  for (int i = 0; i < (int)s.size(); i++) {
    if (s.at(i) == ' ') continue;
    if (s.at(i) < 'a') {
      res += (s.at(i) - 'A') + 'a';
    } else {
      res += s.at(i);
    }
  }
  return res;
}

bool isPermOfPalindrome(string s) {
  s = toLower(s);
  vector<int> cnt(26, 0);
  for (int i = 0; i < (int)s.size(); i++) {
    cnt.at(s.at(i) - 'a')++;
  }

  int num = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt.at(i) % 2 != 0) {
      num++;
      if (num > 1) return false;
    }
  }
  return true;
}

int main() {
  string x = "Tact Coa";
  string ans = isPermOfPalindrome(x) ? "true" : "false";
  cout << ans << endl;
  return 0;
}