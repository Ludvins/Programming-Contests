# include <stdio.h>
# include <math.h>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int primeFactors(int n)
{
  if (n == 1 || n == 2)
    return n;
   if (n%2 == 0)
    {
      return 2;
    }

  for (int i = 3; i <= sqrt(n); i = i+2)
    {
      while (n%i == 0)
        {
          return i;
        }
    }
  return n;
}

int main()
{

  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++){

    int n;
    int l;
    cin >> n >> l;
    vector<int> vec;
    for (int j = 0; j < l; j++)
      {
        int c;
        cin >> c;
        vec.push_back(c);
      }

    vector<int> primes;
    int first_factor =  primeFactors(vec[0]);
    int second_prime = vec[0]/first_factor;


    int aux = first_factor;
    first_factor = second_prime;
    second_prime = aux;


    primes.push_back(first_factor);
    int last_prime = second_prime;
    primes.push_back(last_prime);
    for (int j = 1; j < vec.size(); j++){
      if (vec[j] % last_prime != 0) {
        int aux = first_factor;
        first_factor = second_prime;
        second_prime = aux;
        int last_prime = second_prime;
        primes.clear();
        primes.push_back(first_factor);
        primes.push_back(last_prime);
        for (int j = 1; j < vec.size(); j++){
          last_prime = vec[j]/last_prime;
          primes.push_back(last_prime);
        }
        break;
      }
      last_prime = vec[j]/last_prime;
      primes.push_back(last_prime);
    }

    set<int> s;
    for( unsigned i = 0; i < primes.size(); ++i )
      s.insert( primes[i] );

    map<int, char> alf;
    int j = 0;
    for (auto it : s){
      alf[it] = 65+j;
      j++;
    }

    cout << "Case #" << i + 1 << ": ";
    for(int j = 0; j < primes.size(); j++){
      cout << alf[primes[j]];
    }
    cout << endl;

  }

  return 0;

}
