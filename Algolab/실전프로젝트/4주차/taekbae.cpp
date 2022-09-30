#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct City {
  int id;
  int weight;
};

struct Road {
  int weight;
  City* city1;
  City* city2;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while(tc--) {
      int n, m, a, b;
      cin >> n >> m >> a >> b;

      vector<City> citys;
      vector<Road> roads;

      for(int i=1; i<n+1; i++) {
        City newcity;
        newcity.id = i;
        newcity.weight = 0;
      }

      for(int i=0; i<m; i++) {
        int o, d, c;
        cin >> o >> d >> c;

        Road newroad;
        newroad.city1 = find(citys.begin(), citys.end(), )
      }
    }
    
}