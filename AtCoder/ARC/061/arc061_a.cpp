#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int len = S.size() - 1;
  long long sum = 0;
  for (int bits = 0; bits < (1 << len); bits++) {
    int i0 = 0;
    for (int i = 0; i < len; i++) {
      if ((bits >> i) & 1) {
        string next = S.substr(i0, i - i0 + 1);
        sum += stol(next);
        i0 = i + 1;
      }
    }
    string last = S.substr(i0);
    sum += stol(last);
  }

  cout << sum << endl;
  return 0;
}
