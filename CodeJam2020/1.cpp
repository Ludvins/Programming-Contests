#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int power_of_two(unsigned int x) {
  int i = 1;
  int num = 1;
  while (num < abs(x)) {
    num *= 2;
    i++;
  }
  return i;
}

int main() {
  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++) {
    int x, y;
    cin >> x >> y;

    int x_2 = power_of_two(x);
    cout << x_2 << endl;

    cout << "Case #" << i + 1 << ": " << trace << " " << rows << " " << cols
         << endl;
  }
}
