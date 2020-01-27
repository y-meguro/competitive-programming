#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> t(N);
  vector<P> e;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;

    t.at(a).push_back(b);
    t.at(b).push_back(a);
    e.push_back(make_pair(a, b));
  }

  int maxNum = -1;
  for (int i = 0; i < N; i++) {
    int num = t.at(i).size();
    if (num > maxNum) {
      maxNum = num;
    }
  }
  cout << maxNum << endl;

  queue<int> q;
  q.push(0);
  vector<bool> used(N, false);
  used.at(0) = true;
  vector<int> color(N, 0); // parent color
  map<P, int> m;

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    int c = 1;
    for (int to : t.at(v)) {
      if (used.at(to)) continue;
      if (color.at(v) == c) c++;
      color.at(to) = m[make_pair(to, v)] = m[make_pair(v, to)] = c;
      c++;
      used.at(to) = true;
      q.push(to);
    }
  }

  for (auto p : e) {
    cout << m[p] << endl;
  }

  return 0;
}
