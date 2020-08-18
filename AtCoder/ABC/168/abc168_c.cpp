#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int A, B, H, M;
  cin >> A >> B >> H >> M;
  const double pi = 3.14159265358979323846;
  double longX = sin(M * pi / 30);
  double longY = cos(M * pi / 30);
  double shortX = sin((H * pi / 6) + (M * pi / 360));
  double shortY = cos((H * pi / 6) + (M * pi / 360));

  double ans = sqrt((B * longX - A * shortX) * (B * longX - A * shortX) + (B * longY - A * shortY) * (B * longY - A * shortY));
  cout << fixed << setprecision(20);
  cout << ans << endl;
  return 0;
}