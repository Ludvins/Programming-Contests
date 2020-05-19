
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  int test_cases;
  cin >> test_cases;
  string S;
  getline(cin, S);

  for (int t = 0; t < test_cases; t++) {
    string S, S2;
    getline(cin, S);
    int oppened = 0;

    for (int i = 0; i < S.length(); i++) {
      int value = S.at(i) - 48;
      for (int j = oppened - value; j > 0; j--) {
        S2.push_back(')');
        oppened--;
      }
      for (int j = oppened; j < value; j++) {
        S2.push_back('(');
        oppened++;
      }
      S2.push_back(S.at(i));
    }
    for (int j = 0; j < oppened; j++)
      S2.push_back(')');

    cout << "Case #" << t + 1 << ": " << S2 << endl;
  }
}
