#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N;
vector<vector<vector<double>>> dp;
vector<vector<vector<bool>>> reached;

double dfs(int a, int b, int c) {
  if (a < 0 || b < 0 || c < 0 || a + b + c == 0) return 0;
  if (reached.at(a).at(b).at(c)) return dp.at(a).at(b).at(c);
  reached.at(a).at(b).at(c) = true;
  int s = a + b + c;
  return dp.at(a).at(b).at(c) = (double)N / s + dfs(a - 1, b, c) * ((double)a / s) + dfs(a + 1, b - 1, c) * ((double)b / s) + dfs(a, b + 1, c - 1) * ((double)c / s);
}

int main() {
  cin >> N;

  int x1 = 0;
  int x2 = 0;
  int x3 = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a == 1) x1++;
    if (a == 2) x2++;
    if (a == 3) x3++;
  }

  dp.resize(N + 1, vector<vector<double>>(N + 1, vector<double>(N + 1, 0.0)));
  reached.resize(N + 1, vector<vector<bool>>(N + 1, vector<bool>(N + 1, false)));

  cout << fixed << setprecision(10) << dfs(x1, x2, x3) << endl;
  return 0;
}