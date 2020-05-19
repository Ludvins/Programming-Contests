// Inn the name of God

#include <iostream>
#include <vector>


using namespace std;

int main () {

  int test_cases;
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++){
    int adversaries;
    cin >> adversaries;

    string ret;

    vector<string> advs;
    vector<bool> defeated(adversaries, false);

    for (int i = 0; i < adversaries; i++){
      string str;
      cin >> str;
      advs.push_back(str);
    }

    int c = 0;
    while(true) {

      bool s = true;
      bool p = true;
      bool r = true;

      for (int k = 0; k < advs.size(); k++){
        if(defeated[k])
          continue;

        if (advs[k][c % advs[k].size()] == 'P')
          r = false;
        else if (advs[k][c % advs[k].size()] == 'R')
          s = false;
        else if (advs[k][c % advs[k].size()] == 'S')
          p = false;
      }
      if (!s && !p && !r){
        cout << "Case #" << t+1 << ": IMPOSSIBLE" << endl;
        break;
      }
      else if (s && r){
        ret.push_back('R');
        cout << "Case #" << t+1 << ": " << ret << endl;
        break;
      }
      else if (p && r){
        ret.push_back('P');
        cout << "Case #" << t+1 << ": " << ret << endl;
        break;
      }
      else if (s && p){
        ret.push_back('S');
        cout << "Case #" << t+1 << ": " << ret << endl;
        break;
      }
      else if (s){
        ret.push_back('S');
      }
      else if (p){
        ret.push_back('P');
      }
      else if (r){
        ret.push_back('R');
      }

      char selected = ret[c];

      for (int k = 0; k < advs.size(); k++){
        if(defeated[k])
          continue;

        if ( selected == 'S' && advs[k][c % advs[k].size()] == 'P')
          defeated[k] = true;
        else if (selected == 'P' && advs[k][c % advs[k].size()] == 'R')
          defeated[k] = true;
        else if (selected == 'R' && advs[k][c % advs[k].size()] == 'S' )
          defeated[k] = true;
      }



      c++;
    }


  }

  return 0;
}
