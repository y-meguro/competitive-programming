#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;

  rep(i, N) {
    int A;
    cin >> A;
    if (A % 2 != 0) continue;
    if (A % 3 != 0 && A % 5 != 0) {
      cout << "DENIED" << endl;
      return 0;
    }
  }
  cout << "APPROVED" << endl;
  return 0;
}