#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> ans(N, 0);
  rep(i, N - 1) {
    int A;
    cin >> A;
    A--;
    ans.at(A)++;
  }
  rep(i, N) {
    cout << ans.at(i) << endl;
  }
  return 0;
}