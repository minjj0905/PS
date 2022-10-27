#include <iostream>

#define MAXN 101
using namespace std;

int arr[MAXN + 1][6] = {0};
int dp[MAXN + 1][6] = {0};

int getObstacle(int i, int j) {
    return (arr[i][j - 1] == 1) + (arr[i][j + 1] == 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        fill(&arr[0][0], &arr[MAXN][5], 0); 
        fill(&dp[0][0], &dp[MAXN][5], 0);    
        for(int i=n; i>=1; i--)
            for(int j = 1; j <= 5; j++) cin >> arr[i][j];

        for(int k=2; k<=4; k++) 
            if(arr[1][k] != 1) dp[1][k] = getObstacle(1, k) + arr[1][k];

        for(int i=2; i<=n; i++)
            for(int j=1; j<=5; j++) {
                if(arr[i][j] != 1) dp[i][j] = getObstacle(i, j) + arr[i][j];
                else continue;
                dp[i][j] += max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1]));
        }
        int ans = 0;
        for(int k=1; k<=5; k++) ans = max(ans, dp[n][k]);

        cout << ans << '\n';
    }
}