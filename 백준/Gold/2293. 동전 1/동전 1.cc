#include <iostream>
#define ull unsigned long long
using namespace std;

int min(int a, int b) {
    return a>b ? a : b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k; cin >> n >> k;
    int coin[n];
    for(int i=0; i<n; i++) {
        cin >> coin[i];
    }

    int dp[10001] = {0};
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=coin[i]; j<=k; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }
    
    cout << dp[k] << "\n";
}