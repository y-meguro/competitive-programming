#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1000000007;

int main() {
  int N;
  cin >> N;

  ll A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  ll sum = 0;
  // 各桁について調べる。「0の個数」×「1の個数」に桁分を乗じた数を足していく
  for (ll d = 0; d < 60; d++) {
    ll count0 = 0;
    ll count1 = 0;
    for (ll i = 0; i < N; i++) {
      if((A[i] >> d) & 1LL) {
        count1++;
      } else {
        count0++;
      }
    }
    sum = (sum + (count0 * count1 % mod) * ((1LL << d) % mod) % mod) % mod;
  }

  cout << sum << endl;
  return 0;
}
