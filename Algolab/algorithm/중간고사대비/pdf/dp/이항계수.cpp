#include <iostream>
using namespace std;

#define ull unsigned long long
#define MAX 30
#define MIN(a,b) (a < b ? a : b)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n, k; cin >> n >> k;

        int dp[MAX][MAX] = {0};
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=k; j++) {
                if(i==0 || j==i) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }

        cout << dp[n][k] << "\n";
    }
}