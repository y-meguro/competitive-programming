#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string N;
  cin >> N;
  int cnt = 0;
  rep(i, (int)N.size()) {
    cnt += N[i] - '0';
  }
  if (cnt % 9 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}