#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;

  map<string, int> m;
  rep(i, N) {
    string s;
    cin >> s;

    if (m.count(s)) {
      m.at(s)++;
    } else {
      m[s] = 1;
    }
  }

  int num = 0;
  for (auto e : m) {
    num = max(num, e.second);
  }

  vector<string> ans;
  for (auto e : m) {
    if (e.second == num) {
      ans.push_back(e.first);
    }
  }
  sort(ans.begin(), ans.end());

  for (auto x : ans) {
    cout << x << endl;
  }
  return 0;
}