#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> tree;
vector<int> col;

void dfs(int current, int c) {
  col.at(current) = c;
  for (pair<int, int> e : tree.at(current)) {
    int to = e.first;
    if (col.at(to) != -1) continue;
    int dist = e.second;
    if (dist % 2 == 0) {
      dfs(to, c);
    } else {
      dfs(to, 1 - c);
    }
  }
}

int main() {
  int N;
  cin >> N;
  tree.resize(N);
  col.resize(N, -1);

  for (int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;

    tree.at(u).push_back(make_pair(v, w));
    tree.at(v).push_back(make_pair(u, w));
  }

  dfs(0, 0);

  for (int i = 0; i < N; i++) {
    cout << col.at(i) << endl;
  }

  return 0;
}
