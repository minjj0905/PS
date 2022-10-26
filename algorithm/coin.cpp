#include <iostream>
using namespace std;
#define ull unsigned long long

int sol(int n, int coin[], int k) {
    if(k == 0) return 0;

    int min = 0x7fffffff;
    for(int i=0; i<n; i++) {
        if(k-coin[i] >= 0) {
            int get = sol(n, coin, k-coin[i]);
            if(min>get) min = get;
        }
    }
    return min + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int k; cin >> k;
        int n; cin >> n;
        int coin[n];
        for(int i=0; i<n; i++) cin >> coin[i];

        cout << sol(n, coin, k) << "\n";

    }
}