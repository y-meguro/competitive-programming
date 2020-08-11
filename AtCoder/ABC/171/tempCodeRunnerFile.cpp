
  // ll x = N;
  // ll d = 1;
  // while (x != 0) {
  //   if (x > 26) {
  //     x -= 26;
  //     x /= 26;
  //     d++;
  //   } else {
  //     break;
  //   }
  // }

  // // 文字列を調べる
  // ll a = 26 * ((ll)pow(26, d - 1) - 1) / 25;
  // ll b = N - a - 1;
  // string ans = "";
  // rep (i, d) {
  //   char c = b % 26 + 'a';
  //   b /= 26;
  //   ans = c + ans;
  // }