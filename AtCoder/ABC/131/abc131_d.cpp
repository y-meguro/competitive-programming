#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
  int N;
  cin >> N;

  vector<P> W(N);
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    W.at(i) = P(B, A);
  }
  sort(W.begin(), W.end());

  ll time = 0;
  for (int i = 0; i < N; i++) {
    P p = W.at(i);
    time += p.second;
    if (time > p.first) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
