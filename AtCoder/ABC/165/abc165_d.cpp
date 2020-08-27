#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b, n;
  cin >> a >> b >> n;

  if (b - 1 > n) {
    cout << a * n / b << endl;
  } else {
    cout << a * (b - 1) / b << endl;
  }

  return 0;
}