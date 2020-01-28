#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, W;
  cin >> N >> W;

  vector<ll> v(N), w(N);
  ll sumv = 0;
  ll sumw = 0;
  for (int i = 0; i < N; i++) {
    cin >> v.at(i) >> w.at(i);
    sumv += v.at(i);
    sumw += w.at(i);
  }

  if (N <= 30) {
    // 半分の集合について、全パターンを調べ、vとwの合計をpに入れる
    vector<pair<ll, ll>> p(1 << (N / 2));
    for (int bits = 0; bits < (1 << (N / 2)); bits++) {
      ll ws = 0;
      ll vs = 0;
      for (int i = 0; i < N / 2; i++) {
        if(bits & (1 << i)){
          ws += w.at(i);
          vs += v.at(i);
        }
      }
      p.at(bits) = make_pair(ws, vs);
    }

    // 不要な組み合わせを削除する
    sort(p.begin(), p.end()); // pを重さ順にしておく
    vector<pair<ll, ll>> p2;
    p2.push_back(make_pair(0, 0));
    ll old = -1;
    for (int i = 1; i < (1 << (N / 2)); i++) {
      if (old < p.at(i).second) {
        p2.push_back(p.at(i));
        old = p.at(i).second;
      }
    }

    // 残りの半分と組み合わせる
    ll ans = 0;
    for (int bits = 0; bits < (1 << (N - N / 2)); bits++) {
      ll ws = 0;
      ll vs = 0;
      for (int i = 0; i < (N - N / 2); i++) {
        if(bits & (1 << i)){
          ws += w.at(N / 2 + i);
          vs += v.at(N / 2 + i);
        }
      }
      if(ws <= W){
        int j = upper_bound(p2.begin(), p2.end(), make_pair(W - ws, LLONG_MAX)) - p2.begin();
        ans = max(ans, vs + p2.at(j - 1).second);
      }
    }
    cout << ans << endl;

  } else if (sumw <= 200000) {
    // データセット2はDPで解く
    if (sumw <= W) {
      cout << sumv << endl;
      return 0;
    }

    vector<ll> dp(W + 1, 0);
    for (int i = 0; i < N; i++) {
      for (ll j = W; j >= 0; j--){
        if (j < w.at(i)) continue;
        dp.at(j) = max(dp.at(j), dp.at(j - w.at(i)) + v.at(i));
      }
    }
    cout << dp.at(W) << endl;

  } else {
    // データセット3もDPで解く
    vector<ll> dp(sumv + 1, 1LL << 60);
    dp.at(0) = 0;
    for (int i = 0; i < N; i++) {
      for (ll j = sumv; j >= 0; j--) {
        if (j < v.at(i)) continue;
        dp.at(j) = min(dp.at(j), dp.at(j - v.at(i)) + w.at(i));
      }
    }

    ll ans = 0;
    for (ll i = 0; i <= sumv; i++) {
      if (dp.at(i) <= W) {
        ans = i;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
