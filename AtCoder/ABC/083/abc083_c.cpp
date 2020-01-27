#include <bits/stdc++.h>
using namespace std;

int main() {
  long long X, Y;
  cin >> X >> Y;

  // Xからはじめて2倍ずつして、Yを超えない範囲の数列を考える
  int count = 0;
  while (X <= Y) {
    X *= 2;
    count++;
  }

  cout << count << endl;

  return 0;
}
