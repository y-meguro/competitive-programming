#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int K;
  cin >> K;

  ll x = 7;
  for (int i = 1; i <= K; i++) {
    if (x % K == 0) {
      cout << i << endl;
      return 0;
    }
    x = (x * 10 + 7) % K;
  }

  cout << "-1" << endl;
  return 0;
}