#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll N;
  cin >> N;

  int ac = 0;
  int wa = 0;
  int tle = 0;
  int re = 0;
  rep(i, N) {
    string x;
    cin >> x;
    if (x == "AC") ac++;
    else if (x == "WA") wa++;
    else if (x == "TLE") tle++;
    else re++;
  }

  cout << "AC x " << ac << endl;
  cout << "WA x " << wa << endl;
  cout << "TLE x " << tle << endl;
  cout << "RE x " << re << endl;
  return 0;
}