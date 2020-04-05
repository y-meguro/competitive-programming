#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using P = pair<int, int>;

struct Work {
  int start, end, index;
  Work(int start, int end, int index) : start(start), end(end), index(index) {}
};

bool compare(Work a, Work b) {
  if(a.start == b.start){
    return a.end < b.end;
  } else {
    return a.start < b.start;
  }
}

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;

    vector<Work> ws;
    for (int i = 0; i < N; i++) {
      int S, E;
      cin >> S >> E;
      ws.emplace_back(S, E, i);
    }
    sort(ws.begin(), ws.end(), compare);

    int eC = -1;
    int eJ = -1;
    string ans = "";
    for (int i = 0; i < N; i++) {
      ans += "-";
    }

    for (int i = 0; i < N; i++) {
      Work w = ws.at(i);
      int S = w.start;
      int E = w.end;
      int index = w.index;

      if (eC <= S) {
        eC = E;
        ans.at(index) = 'C';
      } else if (eJ <= S) {
        eJ = E;
        ans.at(index) = 'J';
      } else {
        ans = "IMPOSSIBLE";
        break;
      }
    }
    cout << "Case #" << t + 1 << ": " << ans << endl;
  }
  return 0;
}