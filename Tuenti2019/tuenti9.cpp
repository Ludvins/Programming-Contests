// Inn the name of God

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>
#include <algorithm>    // std::next_permutation, std::sort


using namespace std;

int kanji(int x, int y, int z){

  if (x == -28 && y == -72 && z == -128)
    return 1;

  if (x == -28 && y == -70 && z == -116)
    return 2;

  if (x == -28 && y == -72 && z == -119)
    return 3;

  if (x == -27 && y == -101 && z == -101)
   return 4;

  if (x == -28 && y == -70 && z == -108)
    return 5;

  if (x == -27 && y == -123 && z == -83)
    return 6;

  if (x == -28 && y == -72 && z == -125)
    return 7;

  if (x == -27 && y == -123 && z == -85)
    return 8;

  if (x == -28 && y == -71 && z == -99)
    return 9;

  if (x == -27 && y == -115 && z == -127)
    return 10;

  if (x == -25 && y == -103 && z == -66)
    return 100;

  if (x == -27 && y == -115 && z == -125)
    return 1000;

  if (x == -28 && y == -72 && z == -121)
    return 10000;
  cout << "In the name of GOD" << endl;
  return 0;
}

vector<int> combinations(vector<int> vec){

  vector<int> ret;
  vector<int> multipliers;
  vector<int> scalars;
  for(int v : vec){
    if( v == 10 || v == 100 || v == 1000 || v == 10000){
      multipliers.push_back(v);
    }
    else{
      scalars.push_back(v);
    }
  }

  multipliers.push_back(0);
  while(scalars.size() < multipliers.size())
    scalars.push_back(0);

  sort(multipliers.begin(), multipliers.end(), less<int>());
  sort(scalars.begin(), scalars.end(), less<int>());

  // cout << "Multiplicadores" << endl;
  // for (int a : multipliers){
  //   cout << a << " ";
  // }
  // cout << endl;
  // cout << "Escalares" << endl;
  // for(int a : scalars){
  //   cout << a << " ";
  // }
  // cout << endl;


  do {
    int sum = 0;
    for (int ii = 0; ii < multipliers.size(); ii++){

      if(multipliers[ii] == 10000 && scalars[ii] == 0){
        sum = -1;
        break;
      }
      if(multipliers[ii] == 10 && scalars[ii] == 1){
        sum = -1;
        break;
      }
      if(multipliers[ii] == 100 && scalars[ii] == 1){
        sum = -1;
        break;
      }
      if(multipliers[ii] == 1000 && scalars[ii] == 1){
        sum = -1;
        break;
      }

      if(multipliers[ii]*scalars[ii] == 0)
        sum += multipliers[ii] + scalars[ii];
      else
        sum += multipliers[ii]*scalars[ii];

    }
    if (sum != -1)
      ret.push_back(sum);
  } while ( std::next_permutation(scalars.begin(), scalars.end()) );

  sort(ret.begin(), ret.end(), less<int>());

  // cout << "Permutaciones" << endl;
  // for(int a : ret){
  //   cout << a << " ";
  // }
  // cout << endl;




  return ret;
}



int main () {

  int test_cases;
  cin >> test_cases;

  string msg;

  getline(cin, msg);

  for (int i = 0; i < test_cases; i++){
    // cout << "___________________________________________________________" << endl;
    vector<int> first;
    vector<int> second;
    vector<int> third;
    cin >> msg;

    for (int j = 0; j < msg.size(); j+=3){
      int x = msg[j];
      int y = msg[j+1];
      int z = msg[j+2];

      first.push_back(kanji(x,y,z));
    }
    cin >> msg;
    cin >> msg;

    for (int j = 0; j < msg.size(); j+=3){
      int x = msg[j];
      int y = msg[j+1];
      int z = msg[j+2];
      second.push_back(kanji(x,y,z));
    }
    cin >> msg;

    cin >> msg;

    for (int j = 0; j < msg.size(); j+=3){
      int x = msg[j];
      int y = msg[j+1];
      int z = msg[j+2];

      third.push_back(kanji(x,y,z));
    }


    // cout << "First "<< endl;
    // for(int a : first){
    //   cout << a << " " << endl;
    // }
    // cout << "Second "<< endl;
    // for(int a : second){
    //   cout << a << " " << endl;
    // }
    // cout << "third" << endl;
    // for(int a : third){
    //   cout << a << " " << endl;
    // }

    vector<int> f_c = combinations(first);
    vector<int> f_s = combinations(second);
    vector<int> f_t = combinations(third);

    bool encontrado = false;
    for(int ii : f_c){
      for(int jj : f_s){
        //cout << "Sumando " << ii << " " << jj << endl;
        if(find(f_t.begin(), f_t.end(), ii + jj) != f_t.end()){
          //cout << "Encontrado" << endl;

          cout << "Case #" << i+1 << ": " << ii <<" + " << jj << " = " << ii+jj << endl;
          encontrado = true;
          break;
        }
      }
      if(encontrado)
        break;
    }
    if(!encontrado){
    for(int ii : f_c){
      for(int jj : f_s){
        //cout << "Sumando " << ii << " " << jj << endl;
        if(find(f_t.begin(), f_t.end(), ii - jj) != f_t.end()){
          //cout << "Encontrado" << endl;

          cout << "Case #" << i+1 << ": " << ii <<" - " << jj << " = " << ii-jj << endl;
          encontrado = true;
          break;
        }
      }
      if(encontrado)
        break;
    }
    }

    if(!encontrado){
    for(int ii : f_c){
      for(int jj : f_s){
        //cout << "Sumando " << ii << " " << jj << endl;
        if(find(f_t.begin(), f_t.end(), ii * jj) != f_t.end()){
          //cout << "Encontrado" << endl;

          cout << "Case #" << i+1 << ": " << ii <<" * " << jj << " = " << ii*jj << endl;
          encontrado = true;
          break;
        }
      }
      if(encontrado)
        break;
    }
    }




  }

  return 0;
}
