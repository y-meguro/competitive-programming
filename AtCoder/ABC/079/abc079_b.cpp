#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<ll> lucas(87);
  lucas.at(0) = 2;
  lucas.at(1) = 1;
  for (int i = 2; i <= 86; i++) {
    lucas.at(i) = lucas.at(i - 1) + lucas.at(i - 2);
  }

  cout << lucas.at(N) << endl;
  return 0;
}