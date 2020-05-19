// Inn the name of God

#include <iostream>
#include <vector>
#include <map>
using namespace std;

  vector<vector<char> > m = {
                             {'1','2','3','4','5','6','7','8','9','0'},
                             {'Q','W','E','R','T','Y','U','I','O','P'},
                             {'A','S','D','F','G','H','J','K','L',';'},
                             {'Z','X','C','V','B','N','M',',','.','-'}
  };


int main () {

  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++){

    map<char,pair<int,int>> mymap;
    mymap.clear();
    char author;
    cin >> author;
    string msg;
    getline(cin, msg);
    getline(cin, msg);
    cout << "Author " << author << endl;
    cout << "Mensaje " << msg << endl;
    for (char c : msg){
      if (c == ' '){
        continue;
      }
      for (int ii = 0; ii < 4; ii++){
        for (int jj = 0; jj < 10; jj++){
          if (m[ii][jj] == c){
            mymap[c] = make_pair(ii, jj);
            break;
          }
        }
      }

    }

    char author_c = msg.back();
    cout << "Author enc " << author_c << endl;
    int x, y, x_c, y_c;

    for (int ii = 0; ii < 4; ii++){
      for (int jj = 0; jj < 10; jj++){
        if (m[ii][jj] == author){
          x = ii;
          y = jj;
        }
        if (m[ii][jj] == author_c){
          x_c = ii;
          y_c = jj;
        }
      }
    }


    int x_dif = x - x_c;
    int y_diff = y - y_c;

    cout << "Case #" << i+1 << ": ";

    for (char c : msg){
      if (c == ' '){
        cout << " ";
        continue;
      }
      // cout << "Valores " << mymap[c].first << " " << mymap[c].second << endl;
      // cout << "Diff " << x_dif << " " << y_diff << endl;
      int a = (mymap[c].first + x_dif + m.size())%m.size();
      int b = (mymap[c].second + y_diff + m[0].size())%m[0].size();
      //cout << "s: " << a << " " << b << endl;
      cout << m[a][b];
    }
    cout << endl;



  }

  return 0;
}
