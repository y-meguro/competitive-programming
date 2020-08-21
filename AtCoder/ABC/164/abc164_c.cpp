#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  set<string> S;
  rep(i, N) {
    string x;
    cin >> x;
    S.insert(x);
  }
  cout << S.size() << endl;
  return 0;
}