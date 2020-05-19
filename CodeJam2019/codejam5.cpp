// Inn the name of God

#include <iostream>
#include <vector>
using namespace std;


int rows, cols;

bool expande (vector<vector<char>> &m, int i, int j, char type){
  // cout << "Entra expande " << endl;
  if (type == 'H'){
    for (int ii = i; ii < rows; ii++){
      char aux = m[ii][j];
      if (aux == '.')
        m[ii][j] = '+';
      else if (aux == '#')
        return false;
      else
        break;
    }
    if( i >= 0){
    for (int ii = i-1; ii >= 0 ; ii--){
      char aux = m[ii][j];
      if (aux == '.')
        m[ii][j] = '+';
      else if (aux == '#')
        return false;
      else break;
    }
    }
  }
  if (type == 'V'){
    for (int jj = j; jj < cols; jj++){
      char aux = m[i][jj];
      if (aux == '.')
        m[i][jj] = '+';
      else if (aux == '#')
        return false;
      else break;
    }
    if(j >= 0){
    for (int jj = j-1; jj >= 0 ; jj--){
      char aux = m[i][jj];
      if (aux == '.')
        m[i][jj] = '+';
      else if (aux == '#')
        return false;
      else break;
    }
    }
  }


  return true;
}
bool sub_recursive(vector<vector<char>> &m, char turn){
  // cout << "Sub r" << endl;
  char next_turn;
  if (turn == 'B')
    next_turn = 'T';
  if (turn == 'T')
    next_turn = 'B';

  vector<vector<char> > next1;
  vector<vector<char> > next2;

  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      if (m[i][j] != '.')
        continue;

      next1 = next2 = m;

      if(expande(next1, i, j, 'H')){
        bool a = sub_recursive(next1, next_turn);
        // cout << "Alguien gana" << endl;
        if ( a && turn == 'B')
          return true;
        if (!a && turn  == 'T')
          return false;
      }

      if(expande(next2, i, j, 'V')){
        bool a = sub_recursive(next2, next_turn);
        if ( a && turn == 'B')
          return true;
        if (!a && turn  == 'T')
          return false;
      }

    }
  }
  return turn == 'T';
}
int recursive(vector<vector<char>> &m, char turn){

  char next_turn;
  if (turn == 'B')
    next_turn = 'T';
  if (turn == 'T')
    next_turn = 'B';

  int value = 0;
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){

      if (m[i][j] != '.')
        continue;

      vector<vector<char>> next1 = m;
      if(expande(next1, i, j, 'H') && sub_recursive(next1, next_turn)){
        value++;
      }
      vector<vector<char>> next2 = m;
      if(expande(next2, i, j, 'V') && sub_recursive(next2, next_turn)){
        value++;
      }

    }
  }

  return value;
}



int main () {

  int test_cases;
  cin >> test_cases;

  for (int t = 0; t < test_cases; t++){
    cin >> rows >> cols;

    vector<vector<char>> m;

    for (int i = 0; i < rows; i++){
      vector<char> aux;
      for (int j = 0; j < cols; j++){
        char a;
        cin >> a;
        aux.push_back(a);
      }
      m.push_back(aux);
    }

    cout << "Case #" << t+1 << ": " << recursive(m, 'B') << endl;

 

  }

  return 0;
}
