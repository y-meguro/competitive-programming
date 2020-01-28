#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> w(N);
  for (int i = 0; i < N; i++) {
    cin >> w.at(i);
  }

  vector<int> block;
  for (int i = 0; i < N; i++) {
    int min = 100001;
    int min_pos = -1;
    for (int j = 0; j < block.size(); j++) {
      if (block.at(j) >= w.at(i) && block.at(j) < min) {
        min = block.at(j);
        min_pos = j;
      }
    }
    if (min_pos == -1) {
      block.push_back(w.at(i));
    } else {
      block.at(min_pos) = w.at(i);
    }
  }

  cout << block.size() << endl;

  return 0;
}
