#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll A, B, X;
  cin >> A >> B >> X;

  ll left = 0;
  ll right = 1e9 + 1;
  while (right - left > 1) {
    int N = (right + left) / 2;
    if (A * N + B * to_string(N).size() > X) {
      right = N;
    } else {
      left = N;
    }
  }

  cout << left << endl;

  return 0;
}
