#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int k = sqrt(N);
  for (int i = 2; i <= k; i++) {
    if (N % i == 0) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  return 0;
}
