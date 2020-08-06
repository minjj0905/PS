#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        int sum = 0;
        vector<int> v;

        cin >> n;

        for(int i=0; i<n; i++) {
            int t;
            cin >> t;
            v.push_back(t);
            sum += t;
        }

        double average;
        average = (double) sum / (double) n;

        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(average < v[i]) {
                cnt++;
            }
        }
        cout << fixed;
        cout.precision(3);
        double answer = (double) cnt / (double) n;
        cout << round(answer*100000)/(double)1000 << "%\n";

    }
}