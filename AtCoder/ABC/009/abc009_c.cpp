#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  // アルファベット毎に何文字利用可能かデータを持つ
  vector<int> available(26);
  for (int i = 0; i < N; i++) {
    available[S[i] - 'a']++;
  }

  string ans = S;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 26; j++) {
      if (available[j]) {
        int diff = 0;
        vector<int> tmp = available;
        tmp[j]--;
        for (int k = i + 1; k < N; k++) {
          if (tmp[S[k] - 'a'] == 0) {
            diff++;
          } else {
            tmp[S[k] - 'a']--;
          }
        }
        if (S[i] != 'a' + j) diff++;
        if (diff <= K) {
          ans[i] = 'a' + j;
          available[j]--;
          if(S[i] != 'a' + j) K--;
          break;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
