// Inn the name of God

#include <iostream>
#include <vector>

using namespace std;


int main () {

  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++){

    int n, m;
    cin >> n >> m;

    if (n%2 != 0){
      n++;
    }
    if (m%2 != 0){
      m++;
    }

    cout << "Case #" << i+1 << ": " << (n+m)/2 << endl;


  }

  return 0;
}
