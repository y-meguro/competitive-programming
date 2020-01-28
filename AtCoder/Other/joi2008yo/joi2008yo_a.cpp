#include <bits/stdc++.h>
using namespace std;

int count(int a) {
  return a / 5 + a % 5;
}

int main() {
  int price, change;
  cin >> price;
  change = 1000 - price;

  int ans = 0;
  ans = count(change / 100) + count((change % 100) / 10) + count(change % 10);
  cout << ans << endl;

  return 0;
}
