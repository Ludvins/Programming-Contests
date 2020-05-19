// Inn the name of God

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main () {

  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++){

    int w, h, f, p;
    cin >> w >> h >> f >> p;

    vector<char> folds;
    vector<pair<int,int>> punchs;

    for (int j = 0; j < f ; j++){
      char c;
      cin >> c;
      folds.push_back(c);
    }
    for (int j = 0; j < p ; j++){
      int x, y;
      cin >> x >> y;
      punchs.push_back(pair<int,int>(x,y));
    }

    for (auto fo : folds){
      vector<pair<int,int>> new_vec;
      for (auto pu: punchs){
        pair<int,int> aux = pu;

        switch (fo){
        case 'T':
          aux.second = h + pu.second;
          pu.second = h - pu.second-1;
          new_vec.push_back(aux);
          break;

        case 'B':
          aux.second = pu.second;
          pu.second = 2*h - pu.second-1;
          new_vec.push_back(aux);
          break;

        case 'R':
          aux.first = pu.first;
          pu.first = 2*w - pu.first - 1;
          new_vec.push_back(aux);
          break;
        case 'L':
          aux.first = w + pu.first;
          pu.first = w - pu.first - 1;
          new_vec.push_back(aux);
          break;
        }
        new_vec.push_back(pu);

      }
      punchs = new_vec;
      sort(punchs.begin(), punchs.end());

      switch (fo){
      case 'T':
        h = 2*h;
        break;
      case 'B':
        h = 2*h;
        break;
      case 'L':
        w = w*2;
        break;
      case 'R':
        w = w*2;
        break;
      }
    }


    cout << "Case #" << i+1 << ":" << endl;
    for (auto pu : punchs){
      cout << pu.first << " " << pu.second << endl;
    }


  }

  return 0;
}
