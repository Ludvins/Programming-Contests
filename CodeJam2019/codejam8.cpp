// Inn the name of God

#include <set>
#include <iostream>
#include <vector>
using namespace std;


int count( string str )
{
  int iSpaces = 0;

  for(unsigned int iLoop = 0; iLoop < ( sizeof( str ) / sizeof( str [0] ) ); iLoop++ )
    if(str [iLoop] == ' ' )
      iSpaces++;

  return iSpaces;
}

int main () {

  int test_cases;
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++){
      for (int i = 1; i < 15; i++){
        for (int j = 0; j < 6; j++){
        int day;
        cin >> day;
        cout << i << " " << 100 << endl;
      }
    }
      set<pair<int,int>> vec;
      int a,b,c,d,e;
      int day;
      cin >> day;
      cout << 16 << " " << 0 << endl;
      string line;
      getline(cin, line);
      a = count(line);

      cin >> day;
      cout << 17 << " " << 0 << endl;
      getline(cin, line);
      b = count(line);


      cin >> day;
      cout << 18 << " " << 0 << endl;
      getline(cin, line);
      c = count(line);


      cin >> day;
      cout << 19 << " " << 0 << endl;
      getline(cin, line);
      d = count(line);


      cin >> day;
      cout << 20 << " " << 0 << endl;
      getline(cin, line);
      e = count(line);


      cin >> day;

      vec.insert(make_pair(a, 16));
      vec.insert(make_pair(b, 17));
      vec.insert(make_pair(c, 18));
      vec.insert(make_pair(d, 19));
      vec.insert(make_pair(e, 20));
      vector<pair<int,int>> v (vec.begin(), vec.end());

      cout << v[2].second << " " << 100 << endl;
      cin >> day;
      cout << v[2].second << " " << 100 << endl;
      cin >> day;
      cout << v[1].second << " " << 100 << endl;
      cin >> day;
      cout << v[1].second << " " << 100 << endl;
      cin >> day;
      cout << v[0].second << " " << 100 << endl;

      return 0;
  }
}
