#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    int a, b;

    vector<vector<int>> v;

    while(n--) {
      cin >> a >> b;
      vector<int> xy;
      xy.push_back(a);
      xy.push_back(b);
      v.push_back(xy);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++) {
      cout << v[i][0] << " " << v[i][1] << "\n";
    }
}