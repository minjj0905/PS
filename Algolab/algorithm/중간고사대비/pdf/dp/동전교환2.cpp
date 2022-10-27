#include <iostream>
using namespace std;

#define ull unsigned long long
#define MAX_COINS 101
#define MAX_CHANGE 1001

// pdf 코드
int countCoinExchange(int coins[], int numDiffCoins, int change) {
    int i, j, numComb;
    int N[MAX_COINS][MAX_CHANGE] = {0};

    for(i = 0; i<= numDiffCoins; i++) N[i][0] = 1;

    for(i = 1; i<=numDiffCoins; i++) {
        for(j = 1; j<=change; j++) {
            if(j - coins[i] < 0) numComb = 0;
            else numComb = N[i][j-coins[i]];
            N[i][j] = N[i-1][j] + numComb;
        }
    }

    return N[numDiffCoins][change];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int coin[n+1];
        for(int i=1; i<=n; i++) cin >> coin[i];
        int k; cin >> k;
        
        // 내가 짠거
        int dp[MAX_COINS][MAX_CHANGE] = {0};
        for(int i=0; i<101; i++) {
            dp[i][0] = 1;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=k; j++) {
                if (j - coin[i] < 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j - coin[i]];
            }
        }

        cout << dp[n][k] << ' ' << countCoinExchange(coin, n, k) << "\n";
    }
}