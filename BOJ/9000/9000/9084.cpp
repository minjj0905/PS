#include <iostream>
using namespace std;
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int coin[n];
        for(int i=0; i<n; i++) cin >> coin[i];
        int m; cin >> m;

        int dp[10001] = {0};
        dp[0] = 1;
        for(int i=0; i<n; i++) {
            for(int j=coin[i]; j<=m; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }

        cout << dp[m] << "\n";
    }
}