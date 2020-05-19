// Inn the name of God

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include<sstream>
using namespace std;

map<string, int> value;
map<string, vector<string>> bib;


int recursive(string n){
  if (n == "New Earth"){
    value[n] = 1;
    return 1;
  }
  int sum = value[n];
  for(auto it : bib[n]){

    if (value[it] == 0){
      recursive(it);
    }
    sum += value[it];
  }
  value[n] = sum;
  return sum;
}

int main () {

  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++){
    bib.clear();
    value.clear();
    int nodes;
    cin >> nodes;

    string line;
    getline(cin , line);
    for(int j = 0; j < nodes; j++){

      getline(cin, line);   // get a whole line
      vector<string> vec;

      std::stringstream ss(line);
      string node;
      getline(ss, node, ':');
      value[node] = 0;
      while(getline(ss, line, ',')){
        vec.push_back(line);
        // You now have separate entites here
      }

      bib[node] = vec;
   }

    int p = recursive("Galactica");


    cout << "Case #" << i+1 << ": " << p << endl;

  }

  return 0;
}
