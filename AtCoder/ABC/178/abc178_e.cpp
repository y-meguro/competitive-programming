#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<P> points;
  int minX = 1e9 + 1, minY = 1e9 + 1, maxX = 0, maxY = 0;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    points.push_back(P(x, y));
    minX = min(minX, x);
    minY = min(minY, y);
    maxX = max(maxX, x);
    maxY = max(maxY, y);
  }

  P leftlow = points.at(0), rightlow = points.at(0), lefthigh = points.at(0), righthigh = points.at(0);
  for (int i = 1; i < n; i++) {
    P p = points.at(i);
    if (abs(leftlow.first - minX) + abs(leftlow.second - minY) > abs(p.first - minX) + abs(p.second - minY)) leftlow = p;
    if (abs(rightlow.first - maxX) + abs(rightlow.second - minY) > abs(p.first - maxX) + abs(p.second - minY)) rightlow = p;
    if (abs(lefthigh.first - minX) + abs(lefthigh.second - maxY) > abs(p.first - minX) + abs(p.second - maxY)) lefthigh = p;
    if (abs(righthigh.first - maxX) + abs(righthigh.second - maxY) > abs(p.first - maxX) + abs(p.second - maxY)) righthigh = p;
  }

  int ans = max(abs(righthigh.first - leftlow.first) + abs(righthigh.second - leftlow.second), abs(rightlow.first - lefthigh.first) + abs(rightlow.second - lefthigh.second));
  cout << ans << endl;
  return 0;
}