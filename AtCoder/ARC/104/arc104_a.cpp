#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b;
  cin >> a >> b;
  int x = (a + b) / 2;
  int y = (a - b) / 2;

  cout << x << " " << y << endl;
  return 0;
}