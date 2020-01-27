#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> B(N - 1);
  for (int i = 0; i < N - 1; i++) {
    cin >> B.at(i);
  }

  int sum = B.at(0);
  for (int i = 0; i < N - 2; i++) {
    sum += min(B.at(i), B.at(i + 1));
  }
  sum += B.at(N - 2);

  cout << sum << endl;

  return 0;
}
