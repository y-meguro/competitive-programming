#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string S;
  cin >> S;
  int N = S.size();

  vector<int> ans(N, 0);
  char target = 'R';
  int posR, posL, num;
  rep(i, N) {
    if (S.at(i) == target) {
      num++;
    } else {
      if (target == 'R') {
        target = 'L';
        posR = i - 1;
        posL = i;
        ans.at(posR) += (num + 1) / 2;
        ans.at(posL) += num / 2;
      } else {
        target = 'R';
        ans.at(posR) += num / 2;
        ans.at(posL) += (num + 1) / 2;
      }
      num = 1;
    }
  }
  ans.at(posR) += num / 2;
  ans.at(posL) += (num + 1) / 2;

  rep(i, N) {
    if (i != N - 1) {
      cout << ans.at(i) << " ";
    } else {
      cout << ans.at(i) << endl;
    }
  }
  return 0;
}