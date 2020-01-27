#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int x[4];
  for (int i = 0; i < 4; i++) {
    x[i] = s.at(i) - '0';
  }

  int val = 0;
  string op[3];

  for (int bits = 0; bits < (1 << 3); bits++) {
    val = x[0];
    for (int i = 0; i < 3; i++) {
      if ((bits >> i) & 1) {
        val += x[i + 1];
        op[i] = "+";
      } else {
        val -= x[i + 1];
        op[i] = "-";
      }
    }

    if (val == 7) {
      for (int i = 0; i < 3; i++) {
        cout << x[i] << op[i];
      }
      cout << x[3] << "=7" << endl;
      break;
    }
  }

  return 0;
}
