#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {

  int test_cases;
  cin >> test_cases;
  int lenght;
  cin >> lenght;
  for (int t = 0; t < test_cases; t++) {
    if (lenght == 10) {
      vector<int> ret;
      for (int i = 0; i < lenght; i++) {
        int value;
        cout << i + 1 << endl;
        cin >> value;
        ret.push_back(value);
      }
      for (auto a : ret)
        cout << a;
      cout << endl;
      char result;
      cin >> result;
      if (result == 'N')
        break;
    }

    if (lenght == 20) {

      int relation[10];
      for (int i = 0; i < 10; i++) {
        int value, value2;
        cout << i + 1 << endl;
        cin >> value;
        cout << 20 - i << endl;
        cin >> value2;

        relation[i] = (value + value2) % 2;
      }

      int ret[20];
      for (int i = 0; i < 10; i++) {
        int value;
        cout << i + 1 << endl;
        cin >> value;
        ret[i] = value;
        ret[19 - i] = (value + relation[i]) % 2;
      }
      for (auto a : ret)
        cout << a;
      cout << endl;
      char result;
      cin >> result;
      if (result == 'N')
        break;
    }
  }
}
