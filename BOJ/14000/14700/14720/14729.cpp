#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    vector<double> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        double t; 
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<7; i++) {
        cout << fixed;
        cout.precision(3);
        cout << v[i] << "\n";
    }
}