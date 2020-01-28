#include <bits/stdc++.h>
using namespace std;

void explore(int current, int before, map<int, vector<int>>& graph, vector<bool>& reached, bool& isCycle) {
  if (reached.at(current)) {
    isCycle = true;
    return;
  }
  reached.at(current) = true;

  if (!graph.count(current)) return;
  for (int x : graph.at(current)) {
    if (x == before) continue;
    explore(x, current, graph, reached, isCycle);
  }
}

int main() {
  int N, M;
  cin >> N >> M;

  map<int, vector<int>> graph;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;

    if (graph.count(u - 1)) {
      graph.at(u - 1).push_back(v - 1);
    } else {
      graph[u - 1] = { v - 1 };
    }
    if (graph.count(v - 1)) {
      graph.at(v - 1).push_back(u - 1);
    } else {
      graph[v - 1] = { u - 1 };
    }
  }

  int count = 0;
  vector<bool> reached(N, false);
  for (int i = 0; i < N; i++) {
    // ある頂点から到達するすべての点を塗りつぶす
    if (!reached.at(i)) {
      bool isCycle = false;
      explore(i, -1, graph, reached, isCycle);
      if (!isCycle) {
        count++;
      }
    }
  }

  cout << count << endl;
  return 0;
}
