#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, G;
  cin >> D >> G;

  int p[D], c[D];
  for (int i = 0; i < D; i++) {
    cin >> p[i] >> c[i];
  }

  int min = 1000;
  // コンプリートボーナスのもらい方をパターン分けして、各パターンについて調べる
  for (int bits = 0; bits < (1 << D); bits++) {
    int count = 0;
    int sum = 0;
    for (int i = 0; i < D; i++) {
      if (bits & (1 << i)) {
        count += p[i];
        sum += (i + 1) * 100 * p[i] + c[i];
      }
    }
    if (sum >= G) {
      if (count < min) {
        min = count;
      }
      continue;
    }

    // コンプリートボーナスをもらった上で足りない場合の計算
    for (int i = D - 1; i >= 0; i--) {
      if (!(bits & (1 << i))) {
        if (sum + (i + 1) * 100 * (p[i] - 1) >= G) {
          count += (G - sum) / ((i + 1) * 100);
          if ((G - sum) % ((i + 1) * 100) != 0) {
            count++;
          }
          if (count < min) {
            min = count;
          }
          break;
        } else {
          count += p[i] - 1;
          sum += (i + 1) * 100 * (p[i] - 1);
        }
      }
    }
  }

  cout << min << endl;
  return 0;
}
