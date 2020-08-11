#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll N;
  cin >> N;

  string ans = "";
  while (N > 0) {
    N--;
    ans += (char)(N % 26 + 'a');
    N /= 26;
  }
  reverse(ans.begin(), ans.end());

  cout << ans << endl;
  return 0;
}