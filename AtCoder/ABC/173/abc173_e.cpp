#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll mod = 1e9 + 7;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> pos, neg;
  rep(i, n) {
    cin >> a.at(i);
    if (a.at(i) < 0) neg.push_back(a.at(i));
    else pos.push_back(a.at(i));
  }

  // 正にできるかチェック
  bool ok = true;
  if (pos.size() == 0) {
    ok = (k % 2 == 0);
  } else {
    if (n == k) ok = (neg.size() % 2 == 0);
  }

  mint ans = 1;
  if (!ok) {
    // 正にできない場合は絶対値の小さい順に取る
    sort(a.begin(), a.end(), [](int x, int y) {
      return abs(x) < abs(y);
    });
    rep(i, k) ans *= a.at(i);
  } else {
    // 正にできる場合は絶対値の大きいペアから順に取る
    sort(pos.begin(), pos.end()); // 絶対値の大きいほうが後ろ
    sort(neg.rbegin(), neg.rend());

    if (k % 2 != 0) {
      ans = pos.back();
      pos.pop_back();
    }

    vector<ll> p;
    while (pos.size() > 1) {
      ll tmp = pos.back(); pos.pop_back();
      tmp *= pos.back(); pos.pop_back();
      p.push_back(tmp);
    }
    while (neg.size() > 1) {
      ll tmp = neg.back(); neg.pop_back();
      tmp *= neg.back(); neg.pop_back();
      p.push_back(tmp);
    }
    sort(p.rbegin(), p.rend());

    rep(i, k/2) ans *= p.at(i);
  }

  cout << ans << endl;
  return 0;
}