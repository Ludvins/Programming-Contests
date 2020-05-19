#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct act {
  int start;
  int end;
  mutable char p;
  int pos;
};

bool cmp(act a, act b) {
  return a.start < b.start or (a.start == b.start and a.end <= b.end);
};

bool cmp2(act a, act b) { return a.pos < b.pos; };

int main() {
  int test_cases;
  cin >> test_cases;
  string S;
  getline(cin, S);

  for (int t = 0; t < test_cases; t++) {
    int activities;
    set<act, decltype(cmp) *> hours(cmp);
    cin >> activities;
    for (int a = 0; a < activities; a++) {
      int s, e;
      cin >> s >> e;
      hours.insert({s, e, ' ', a});
    }

    int c_end = 0;
    int j_end = 0;
    bool impossible = false;
    for (auto a = hours.begin(); a != hours.end(); a++) {
      if (a->start >= c_end) {
        a->p = 'C';
        c_end = a->end;
      } else if (a->start >= j_end) {
        j_end = a->end;
        a->p = 'J';
      } else {
        impossible = true;
        break;
      }
    }
    if (impossible)
      cout << "Case #" << t + 1 << ": IMPOSSIBLE" << endl;
    else {
      set<act, decltype(cmp2) *> hours2(hours.begin(), hours.end(), cmp2);

      string ret;
      for (auto a : hours2) {
        ret.push_back(a.p);
      }
      cout << "Case #" << t + 1 << ": " << ret << endl;
    }
  }
}
