#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1) {
        vector<int> v;
        for(int i=0; i<3; i++) {
            int t;
            cin >> t;
            v.push_back(t);
        }
        sort(v.begin(), v.end());
        if(v[2] == 0) break;

        if(v[2]*v[2] == v[0]*v[0] + v[1]*v[1]) {
            cout << "right" << "\n";
        }
        else {
            cout << "wrong" << "\n";
        }
        v.clear();
    }
}