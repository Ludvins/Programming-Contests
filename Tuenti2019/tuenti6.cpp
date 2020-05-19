// Inn the name of God

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<char>> m;
map<char, set<char>> my_map;
map<char, int> value;
map<char, vector<char>> path;

int recursive(char c){

  //cout << "Resursive " << c << endl;
  if (my_map[c].empty()){
    value[c] = 1;
    path[c].push_back(c);
    return 1;
  }

  int ma = 0;
  for(auto it : my_map[c]){
    //cout << "Explorando " << it << endl;
    if (value.find(it) == value.end()){
      recursive(it);
    }
    //cout << "Value: " << value[it] << endl;
    if (value[it] + 1 > ma){
      ma = value[it] + 1;
      path[c] = path[it];
      path[c].push_back(c);
    }
  }
  value[c] = ma;
  return ma;

}


int main () {

  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++){

    int messages;
    cin >> messages;

    m.clear();
    my_map.clear();
    path.clear();
    value.clear();

    //cout << "MENSAJE" << endl;
    for (int j = 0; j < messages; j++){
      string str;
      cin >> str;
      //cout << str << endl;
      m.push_back(vector<char>(str.begin(), str.end()));
    }
    //cout << "--MENSAJE" << endl;

    set<char> aux;
    for(auto a : m){
      aux.insert(a.begin(), a.end());
    }

    int n_l = aux.size();
    //cout << "TAMAÑO: "<< n_l << endl;

    if (m.size() == 1){
      set<char> aux(m[0].begin(), m[0].end());
      if(aux.size() == 1){
        cout << "Case #" << i+1 << ": " << m[0][0] << endl;;
      }
      else{
        cout << "Case #" << i+1 << ": AMBIGUOUS" << endl;
      }
      continue;
    }

    for (auto it = m.begin(); it != m.end(); it++){
      auto next = it;
      next++;
      if(next == m.end()){
        break;
      }

      for(int k = 0; k < it->size(); k++ ){
        if(it->at(k) != next->at(k)){
          my_map[next->at(k)].insert(it->at(k));
          break;
        }
      }
    }


    // for (auto m : my_map){
    //   cout << "Llave: " << m.first << endl;
    //   for(auto v : m.second){
    //     cout << " " << v;
    //   }
    //   cout << endl;
    // }

    bool found = false;
    for (auto m : my_map){
      if(recursive(m.first) == n_l){
        found = true;
        // cout << "encontrado" << endl;
        cout << "Case #" << i+1 << ":";
        for(auto b : path[m.first]){
          cout << " " <<  b;
        }
        cout << endl;
        break;
      }

    }
    if(!found)
    cout << "Case #" << i+1 << ": AMBIGUOUS" << endl;


  }

  return 0;
}
