#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  set<int> d;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    d.insert(x);
  }

  cout << d.size() << endl;
  return 0;
}
