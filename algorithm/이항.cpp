#include <iostream>
using namespace std;
#define ull unsigned long long

ull sol_arr[101][101] = {0};

ull sol(int n, int k) {
    if(n ==0 || k==n) return 1;
    if(sol_arr[n][k] == 0) {
        sol_arr[n][k] = sol(n-1, k-1) + sol(n-1, k);
    }
    return sol_arr[n][k] % 10000;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<101; i++) {
        sol_arr[i][0] = 1;
    }
    
    int tc; cin >> tc;
    while(tc--) {
        int n ,k; cin >> n >> k;
        cout << sol(n, k) % 1000 << "\n";
    }
}