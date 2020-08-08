#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<int> A(9);
  rep(i, 9) {
    cin >> A.at(i);
  }

  int N;
  cin >> N;
  vector<bool> check(9, false);
  rep(i, N) {
    int b;
    cin >> b;
    rep(j, 9) {
      if (A.at(j) == b) {
        check.at(j) = true;
      }
    }
  }

  set<int> s;
  if ((check.at(0) && check.at(1) && check.at(2)) || (check.at(3) && check.at(4) && check.at(5)) || (check.at(6) && check.at(7) && check.at(8)) || (check.at(0) && check.at(3) && check.at(6)) || (check.at(1) && check.at(4) && check.at(7)) || (check.at(2) && check.at(5) && check.at(8)) || (check.at(0) && check.at(4) && check.at(8)) || (check.at(2) && check.at(4) && check.at(6))) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}