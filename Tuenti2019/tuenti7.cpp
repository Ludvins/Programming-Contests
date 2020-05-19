// Inn the name of God

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> notSoComplexHash(string &inputText) {
  vector<int> hash = vector<int>(16, 0);

  for (int i = 0, j = 0; i < inputText.length(); i++) {

    if (inputText[i] != '\r' && inputText[i] != '\n') {
      hash[j % 16] = (char) (hash[j % 16] + inputText[i]);
      j++;
    }

  }

  for (int &h : hash){
    h = h%256;
  }

  return hash;
}


int main () {

  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++){

    int lines;
    cin >> lines;

    stringstream ss;
    string msg;
    getline(cin, msg);
    for (int j = 0; j < lines; j++){
      getline(cin , msg);
       ss << msg;
    }
    msg = ss.str();
    // cout << msg << endl;;

    vector<int> original = notSoComplexHash(msg);


    int lines2;
    cin >> lines2;
    getline(cin, msg);
    stringstream ss2;
    string msg2;
    int pos;
    for (int j = 0; j < lines2; j++){
      getline(cin , msg2);
      ss2 << msg2;
    }
    msg2 = ss2.str();
    pos = msg2.find_first_of('-') + 3;
    // cout << msg2 << endl;

    const vector<int> altered = notSoComplexHash(msg2);
    string first = msg2.substr(0, pos);
    string second = msg2.substr(pos, msg2.length());
    // cout << "First: " << first << endl;
    // cout << "Second: " << second << endl;

    // for (int j = 0; j < original.size(); j++){
    //   cout << original[j] << " " ;
    // }
    // cout << endl;

    // for (int j = 0; j < original.size(); j++){
    //   cout << altered[j] << " " ;
    // }
    // cout << endl;

    // cout << "posicion donde acaba el string:" << pos%16 << endl;

    for (int size = 0; true; size++){
      // cout << "---------------------------Probando tamaño " << size << endl;

      string zero (size, '0');
      string aux = first;
      aux.append(zero.begin(), zero.end());
      aux.append(second.begin(), second.end());

      // cout << "Mostrando situacion: " << endl;
      // for(int k = 0; k < aux.size(); k++){
      //   if(k%16 == 0)
      //     cout << endl;
      //   cout << aux[k];
      // }
      // cout << endl;

      const vector<int> calc0 = notSoComplexHash(aux);

      map<int, vector<int>> positions;
      bool correct_size = true;
      for (int k = 0; k < 16; k++){
         // cout << "Valor 0: " << calc0[k] << "  valor obj: " << original[k] << endl;
        int pos_vec = (k + 16 - pos%16)%16;
        // cout << "Posiciones de la columna " << k << " en el vector:";

        // NOTE Calcula posicoines
        while(true){
          // cout << pos_vec << " ";
          positions[k].push_back(pos_vec);
          if(pos_vec + 16 >=size)
            break;
          pos_vec = pos_vec + 16;
        }
        // cout << endl;
        //cout << "A" << positions[k].size() << endl;
        int upper_bound = positions[k].size()*(122-48);
        int difer = (original[k] - calc0[k] + 256)%256;
        // cout << "Numero de 0 que tengo: " << positions[k].size() << endl;
        // cout << "Diferencia: " << difer << endl;
        // cout << "Valor no acotado con z's: " << upper_bound << endl;

        if ( upper_bound < difer){
          // cout << "No se puede alcanzar." << endl;
          correct_size = false;
          break;
        }
        bool inter = false;
        for (int ii = 0; original[k] + ii*256 < calc0[k] + upper_bound; ii++){
          if (original[k] + ii*256 > calc0[k]){
            // cout << "Se Puede" << endl;
            inter = true;
            break;
          }
        }

        if (!inter){
          // cout << "No enrta en el intervalo " << endl;
          correct_size = false;
          break;
        }


      }

      if (correct_size){
        //cout << "ES EL TAMAÑO CORRECTO----------------------------------------" << endl;

        for (int k = 0; k < 16; k++){
          // cout << "Columna " << k << ", la diferencia es: " << calc0[k] << " " << original[k] << endl;
          int dif = (original[k] - calc0[k] + 256)%256;
          for (auto pos = positions[k].rbegin(); pos != positions[k].rend(); pos++){
            // cout << "Posicion: " << *pos <<  "  dif: " << dif << endl;
            if (dif >= 74){
              zero.at(*pos) = 'z';
              dif -= 74;
            }
            else{
              zero.at(*pos) += dif;
              dif = 0;
            }
            //cout << "Valor insertado: " << zero.at(*pos) << endl;
          }
        }

        //break;

        string limao = first;
        limao.append(zero.begin(), zero.end());
        limao.append(second.begin(), second.end());

        // cout << "Mostrando situacion: " << endl;
        // for(int k = 0; k < limao.size(); k++){
          // if(k%16 == 0)
            // cout << endl;
          // cout << limao[k];
        // }
        // cout << endl;

        // vector<int> lemao = notSoComplexHash(limao);
        // for (int j = 0; j < lemao.size(); j++){
        //   cout << lemao[j] << " " ;
        // }
        // cout << endl;

        // for (int j = 0; j < original.size(); j++){
        //   cout << original[j] << " " ;
        // }
        // cout << endl;

        // for (int j = 0; j < original.size(); j++){
        //   cout << altered[j] << " " ;
        // }
        // cout << endl;

        cout << "Case #" << i + 1<< ": " << zero << endl;

        // cout << "Mostrando situacion: " << endl;
        // for(int k = 0; k < aux.size(); k++){
        //   if(k%16 == 0)
        //     cout << endl;
        //   cout << aux[k];
        // }
        // cout << endl;

        // aux = first;
        // aux.append(as.begin(), as.end());
        // aux.append(second.begin(), second.end());

        // cout << "Mostrando situacion: " << endl;
        // for(int k = 0; k < aux.size(); k++){
        //   if(k%16 == 0)
        //     cout << endl;
        //   cout << aux[k];
        // }
        // cout << endl;

        break;


      }


    }
  }
  return 0;
}
