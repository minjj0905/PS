#include <iostream>
using namespace std;
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int k, n; cin >> k >> n;

        int dp[15][15] = {0};
        for(int i=1; i<=14; i++) dp[0][i] = i;

        for(int i=1; i<=k; i++) {
            for(int j=1; j<=n; j++) {
                int sum = 0;
                for(int m=1; m<=j; m++) sum += dp[i-1][m];
                dp[i][j] = sum;
            }
        }

        cout << dp[k][n] << "\n";
    }
}