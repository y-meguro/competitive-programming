#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;

  vector<bool> AC(N, false);
  vector<int> WA(N, 0);
  rep(i, M) {
    int p;
    string s;
    cin >> p >> s;
    p--;

    if (AC.at(p)) continue;
    if (s == "AC") {
      AC.at(p) = true;
    } else {
      WA.at(p)++;
    }
  }

  int numA = 0;
  int numW = 0;
  rep(i, N) {
    if (AC.at(i)) {
      numA++;
      numW += WA.at(i);
    }
  }
  cout << numA << " " << numW << endl;
  return 0;
}