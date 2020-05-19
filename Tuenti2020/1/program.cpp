

 #include <cmath>
 #include <iostream>
 #include <set>
 #include <vector>
 using namespace std;

 int main() {
   int cases;
   cin >> cases;

   for (int i = 0; i < cases; i++) {

     char a, b, ret;
     cin >> a >> b;

     if (a == b)
       ret = '-';
     else if ((a == 'P' and b == 'S') or (a == 'S' and b == 'P'))
       ret = 'S';
     else
       ret = (char)min(a, b);

     cout << "Case #" << i + 1 << ": " << ret << endl;
   }
 }
