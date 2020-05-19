// Inn the name of God

#include <iostream>
#include <vector>
using namespace std;


int main () {

  int test_cases;
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++){

    int n;
    cin >> n;

    vector<pair<int,int>> mols;
    for (int i = 0; i < n; i++) {
      int a,b;
      cin >> a >> b;
      mols.push_back(make_pair(a, b));
    }

    bool a = true;
    for (int c = 1; c < 10000; c++){
      for (int j = 1; j < 10000; j++){
        a = true;
        for (int k = 0; k < mols.size()-1; k++){
          if ((mols[k+1].first - mols[k].first)*c + (mols[k+1].second - mols[k].second)*j <= 0){
            a = false;
            break;
          }
        }
        if (a){
          cout << "Case #" << t+1 << ": " << c << " " << j << endl;
          break;
        }
      }
      if (a)
        break;
    }
    if (!a)
      cout << "Case #" << t+1 << ": IMPOSSIBLE"  << endl;
 
  }

  return 0;
}
