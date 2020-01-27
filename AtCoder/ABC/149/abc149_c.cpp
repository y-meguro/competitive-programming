#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;

  while (true) {
    int n = sqrt(X);
    bool ok = true;
    for (int i = 2; i <= n; i++) {
      if (X % i == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << X << endl;
      break;
    }
    X++;
  }

  return 0;
}
