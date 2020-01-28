#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<string> num(10);
set<string> result;

void create(int count, string str, vector<bool>& used) {
  if (count) {
    for (int i = 0; i < n; i++) {
      if (used.at(i)) continue;
      used.at(i) = true;
      create(count - 1, str + num.at(i), used);
      used.at(i) = false;
    }
  } else {
    result.insert(str);
  }
}

int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> num.at(i);
  }

  vector<bool> used(n, false);
  create(k, "", used);

  cout << result.size() << endl;

  return 0;
}
