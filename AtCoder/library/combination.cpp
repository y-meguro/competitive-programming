// 二項係数の計算(n <= 10^7 程度まで)
// https://drken1215.hatenablog.com/entry/2018/06/08/210000
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1e9 + 7;
const int MAX = 510000; // 二項係数を求める最大の自然数
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void comInit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
ll combination(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// 使用例
int main() {
  // 前処理
  comInit();

  // 計算例
  cout << combination(100000, 50000) << endl;

  return 0;
}