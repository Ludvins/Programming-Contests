// Inn the name of God

#include <iostream>
#include <vector>


using namespace std;

int main () {

  int test_cases;
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++){

    int n, k;
    cin >> n >> k;

    int fair = 0;

    vector<int> c, d;
    for (int i = 0; i < n; i++){
      int aux;
      cin >> aux;
      c.push_back(aux);
    }
    for (int i = 0; i < n; i++){
      int aux;
      cin >> aux;
      d.push_back(aux);
    }

    int best_c, best_d;
    for (int i = 0; i < n; i++){
      best_c = c[i];
      best_d = d[i];
      for(int j = i; j < n; j++){

        best_c = max(best_c, c[j]);
        best_d = max(best_d, d[j]);

        if (abs(best_c - best_d) <= k){
          fair++;
        }
      }
    }

    cout << "Case #" << t + 1 << ": " << fair << endl;
  }

  return 0;
}
