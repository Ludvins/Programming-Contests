// Inn the name of God

#include <iostream>
#include <vector>

using namespace std;


int main () {

  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++){
    int p, q;
    cin >> p >> q;
    vector<int> row (q + 1, 0);
    vector<vector<int>> m (q + 1, row);

    int min_x = 0, min_y= 0;
    int value = 0;

    for (int j = 0; j < p; j++){
      int x, y;
      char d;
      cin >> x >> y;
      cin >> d;

      if (d == 'N'){
        for (int a = 0; a <= q - y - 1; a++){
          for (int b = 0; b <= q; b++){
            m[a][b]++;
          }
        }
      }
       else if (d == 'E'){
         for (int a = 0; a <= q; a++){
           for (int b = x + 1; b <= q; b++){
             m[a][b]++;
           }
         }
      }
       else if (d == 'S'){
         for (int a = q - y + 1; a <= q ; a++){
           for (int b = 0; b <= q; b++){
             m[a][b]++;
           }
         }
       }

       else if (d == 'W'){
         for (int a = 0; a <= q; a++){
           for (int b = 0; b < x ; b++){
             m[a][b]++;
           }
         }
       }

      for (int b = 0; b <= q; b++){
      for (int a = q ; a >= 0; a--){
        cout << m[a][b];
          if (m[a][b] > value){
            value = m[a][b];
            min_x = a;
            min_y = b;
          }
        }
      }


    }

    cout << "Case #" << i + 1 << ": " << min_y << " " << q - min_x  << endl;;
  }

  return 0;
}
