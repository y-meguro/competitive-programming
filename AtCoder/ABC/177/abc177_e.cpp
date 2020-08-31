#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int A = 1e6 + 1;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> c(A, 0);
  rep(i, n) {
    cin >> a.at(i);
    c.at(a.at(i))++;
  }

  bool pairwise = true;
  for (int i = 2; i < A; i++) {
    int cnt = 0;
    for (int j = i; j < A; j += i) {
      cnt += c.at(j);
    }
    if (cnt > 1) {
      pairwise = false;
      break;
    }
  }

  if (pairwise) {
    cout << "pairwise coprime" << endl;
    return 0;
  }

  int g = 0;
  rep(i, n) g = __gcd(g, a.at(i));
  if (g == 1) {
    cout << "setwise coprime" << endl;
  } else {
    cout << "not coprime" << endl;
  }
  return 0;
}