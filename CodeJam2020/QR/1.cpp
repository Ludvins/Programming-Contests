#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++) {
    int dims;
    cin >> dims;
    vector<set<int>> sets(dims);

    int cols = 0, rows = 0, trace = 0;

    for (int ii = 0; ii < dims; ii++) {
      set<int> aux;
      for (int jj = 0; jj < dims; jj++) {
        int value;
        cin >> value;

        aux.insert(value);
        sets[jj].insert(value);

        if (ii == jj)
          trace += value;
      }
      if (aux.size() != dims)
        rows++;
    }
    for (int k = 0; k < dims; k++) {
      if (sets[k].size() != dims)
        cols++;
    }
    cout << "Case #" << i + 1 << ": " << trace << " " << rows << " " << cols
         << endl;
  }
}
