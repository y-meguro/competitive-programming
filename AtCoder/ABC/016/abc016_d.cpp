#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int Ax, Ay, Bx, By, N;
  cin >> Ax >> Ay >> Bx >> By >> N;

  vector<ll> X(N);
  vector<ll> Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
  }

  int num = 0;
  for (int i = 0; i < N; i++) {
    ll x1 = X.at(i);
    ll y1 = Y.at(i);
    ll x2 = X.at((i + 1) % N);
    ll y2 = Y.at((i + 1) % N);

    ll c1 = (By - Ay) * (x1 - Ax) - (Bx - Ax) * (y1 - Ay);
    ll c2 = (By - Ay) * (x2 - Ax) - (Bx - Ax) * (y2 - Ay);
    ll c3 = (y2 - y1) * (Ax - x1) - (x2 - x1) * (Ay - y1);
    ll c4 = (y2 - y1) * (Bx - x1) - (x2 - x1) * (By - y1);

    if (c1 * c2 < 0 && c3 * c4 < 0) {
      num++;
    }
  }

  cout << num / 2 + 1 << endl;

  return 0;
}
