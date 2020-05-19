
 #include <algorithm>
 #include <cmath>
 #include <iostream>
 #include <map>
 #include <set>
 #include <vector>
 using namespace std;

 int main() {
   int cases;
   cin >> cases;

   for (int i = 0; i < cases; i++) {
     map<int, int> values;
     set<pair<int, int>> recount;
     int matches;
     cin >> matches;

     for (int j = 0; j < matches; j++) {
       int a, b, c;
       cin >> a >> b >> c;
       if (recount.count(make_pair(a, b)) == 0) {
         recount.insert(make_pair(a, b));
         if (c == 1) {
           values[a]++;
         } else {
           values[b]++;
         }
       }
     }
     for (auto o : values)
       cout << o.first << " " << o.second << endl;
     auto pr = max_element(values.begin(), values.end(),
                           [](const pair<int, int> &a, const pair<int, int> &b) {
                             return a.second < b.second;
                           });
     cout << "Case #" << i + 1 << ": " << pr->first << endl;
   }
 }
