#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string S, T, U;
  cin >> S >> T;
  int A, B;
  cin >> A >> B >> U;

  if (U == S) {
    cout << A - 1 << " " << B << endl;
  } else {
    cout << A << " " << B - 1 << endl;
  }

  return 0;
}