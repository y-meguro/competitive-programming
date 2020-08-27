#include <bits/stdc++.h>
using namespace std;

string urlify(string s, int len) {
  string res = "";
  int cnt = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s.at(i) == ' ') res += "%20";
    else res += s.at(i);
    cnt++;
    if (cnt == len) return res;
  }
  return "false";
}

int main() {
  string x = "Mr John Smith     ";
  int len = 13;
  cout << urlify(x, len) << endl;
  return 0;
}