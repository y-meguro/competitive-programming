#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int count2(ll a) {
  int cnt = 0;
  while (a % 2 == 0) {
    cnt++;
    a /= 2;
  }
  return cnt;
}

int main() {
  ll N, M;
  cin >> N >> M;

  vector<ll> a(N);
  rep(i, N) cin >> a.at(i);

  int num2 = count2(a.at(0));
  if (num2 == 0) {
    cout << "0" << endl;
    return 0;
  }

  rep(i, N) {
    int c = count2(a.at(i));
    if (c != num2) {
      cout << "0" << endl;
      return 0;
    }
  }

  ll lcm = pow(2, num2);
  rep(i, N) {
    int y = __gcd(lcm, a.at(i));
    lcm = lcm * a.at(i) / y;
  }
  cout << (M + lcm/2) / lcm << endl;
  return 0;
}