#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  set<int> s;
  rep(i, N) {
    int a;
    cin >> a;
    s.insert(a);
  }

  if ((int)s.size() == N) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}