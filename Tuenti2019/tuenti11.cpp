// Inn the name of God

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Moon {
public:
  int id;
  float distance_from_planet;
  float initial_position;
  int orbital_period;
  int unobtanium;
  bool visited = false;

  Moon(int i, float d, float r, int t, int u){
    id = i;
    distance_from_planet = d;
    initial_position = r;
    orbital_period = t;
    unobtanium = u;
  }

  float greedy_value (Moon other){
    return unobtanium/distance(other);
  }

  float distance (Moon other){
    return distance_from_planet * distance_from_planet + other.distance_from_planet * other.distance_from_planet - 2*distance_from_planet*other.distance_from_planet*cos(initial_position - other.initial_position);
  }

  float distance(vector<Moon> &v, int id){
    if (id == -1)
      return distance_from_planet;

    return distance(v[id]);
  }
  void update_position(int hours){
    initial_position = fmod(initial_position + 2*M_PI/orbital_period * hours, 2*M_PI);
  }

  bool can_go_and_return(float fuel, int distance){
    return fuel >= distance + distance_from_planet;
  }

};

int greedyest_moon(vector<Moon> &moons, int position, float fuel, int capacity){
  int nearest = -1;
  float value = MAXFLOAT;

  if (position == -1){
    for (Moon m : moons){
      if (!m.visited && m.unobtanium/m.distance_from_planet < value && m.can_go_and_return(fuel, m.distance_from_planet) && m.unobtanium < capacity){
        nearest = m.id;
        value = m.unobtanium/m.distance_from_planet;
      }
    }
  }
  else {
    for (Moon m : moons){
      if (!m.visited && moons[position].greedy_value(m) < value && m.can_go_and_return(fuel, m.distance(moons[position])) && m.unobtanium < capacity){
        nearest = m.id;
        value = moons[position].greedy_value(m) ;
      }
    }
  }
  return nearest;
}

void update_system(vector<Moon> &v, int h){
  for (Moon m : v)
    m.update_position(h);
}


int main () {

  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++){
    // --------------------------------------------------
    // ------------------- Init -------------------------
    int n_moons;
    cin >> n_moons;
    vector<Moon> moons;
    int passed_hours = 0;

    vector<float> distances;
    vector<float> radius;
    vector<int> periods;
    vector<int> unobtanium;

    for (int j = 0; j < n_moons; j++){
      float d;
      cin >> d;
      distances.push_back(d);
    }
    for (int j = 0; j < n_moons; j++){
      float r;
      cin >> r;
      radius.push_back(r);
    }
    for (int j = 0; j < n_moons; j++){
      int p;
      cin >> p;
      periods.push_back(p);
    }
    for (int j = 0; j < n_moons; j++){
      int u;
      cin >> u;
      unobtanium.push_back(u);
    }

    for (int j = 0; j < n_moons; j++){
      cout << "Leyendo luna" << endl;
      moons.push_back(Moon(j,distances[j], radius[j] , periods[j] , unobtanium[j]));

      cout << "Leida luna: " << endl;
    }
    int capacity;
    cin >> capacity;
    int fuel;
    cin >> fuel;

    // --------------------------------------------------
    // --------------------------------------------------

    int position = -1;
    vector<int> visited;
    while (true) {
      int next_moon = greedyest_moon(moons, position, fuel, capacity);
      if (next_moon == -1){
        cout << "HAHA" << endl;
        break;
      }

      visited.push_back(next_moon);
      moons[next_moon].visited = true;
      capacity -= moons[next_moon].unobtanium;
      fuel -= moons[position].distance(moons, next_moon);
      position = next_moon;
      update_system(moons, 6);
      }



  }

  return 0;
}
