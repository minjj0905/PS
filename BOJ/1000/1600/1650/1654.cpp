#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long k, n;
    cin >> k >> n;
    vector<long long> v;
    for(int i=0; i<k; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }

    long long l = 1, r = *max_element(v.begin(), v.end());

    while(l <= r) {
        long long m = (l+r)/2;
        long long s = 0;

        for(int i=0; i<k; i++) {
            s += v[i]/m;
        }

        if(s>=n) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << l-1;
}