// Inn the name of God

#include <iostream>
#include <vector>
using namespace std;




int main () {

  int test_cases;
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++){
    int f;
    cin >> f;

    for (int pos = 0; pos < 5; pos++){

      vector<int> aux(5,0);

      for (int i = 0 ; i < 120; i++){

        bool lemao = true;
        bool lemao2 = true;
        int ja = -1;
        for (int j = 0; j < 5; j++){
          if(lemao2 && !lemao && aux[j] != 24){
            lemao2 = false;
            break;
          }
          if(lemao && aux[j] != 24){
            lemao = false;
            ja = j;
          }
        }
        if (lemao2){
          if (ja == 0){
            cout << 'A';
          }
          if (ja == 1){
            cout << 'B';
          }
          if (ja == 2){
            cout << 'C';
          }
          if (ja == 3){
            cout << 'D';
          }
          if (ja ==4){
            cout << 'E';
          }
        }


        char c;
        cout << (5*i)+ pos +1;
        cin >> c;
        if (c == 'A')
          aux[0]++;
        if (c == 'B')
          aux[1]++;
        if (c == 'C')
          aux[2]++;
        if (c == 'D')
          aux[3]++;
        if (c == 'E')
          aux[4]++;
   }
      }




  }

  return 0;
}
