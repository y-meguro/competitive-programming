#include <bits/stdc++.h>
using namespace std;

int N, M;
bool relation[8][8];

int search(int current, vector<bool>& visited) {
  bool all_visited = true;
  for (int i = 0; i < visited.size(); i++) {
    if (!visited.at(i)) {
      all_visited = false;
    }
  }
  if (all_visited) return 1;

  int result = 0;
  for (int i = 0; i < N; i++) {
    if (!relation[current][i]) continue;
    if (visited.at(i)) continue;

    visited.at(i) = true;
    result += search(i, visited);
    visited.at(i) = false;
  }
  return result;
}

int main() {
  cin >> N >> M;

  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    relation[a - 1][b - 1] = true;
    relation[b - 1][a - 1] = true;
  }

  vector<bool> visited(N, false);
  visited.at(0) = true;

  int result = search(0, visited);
  cout << result << endl;

  return 0;
}
