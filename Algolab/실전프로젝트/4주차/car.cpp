#include <bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 101
 
using namespace std;

int arr[MAXN + 1][5 + 1] = {0, }, dp[MAXN + 1][5 + 1] = {0, };

int getObstacle(int i, int j) {
    return (arr[i][j - 1] == 1) + (arr[i][j + 1] == 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        memset(arr, 0, sizeof(arr)); // arr, dp initialization
        memset(dp, 0, sizeof(dp));    
        for(int i = n; i >= 1; i--)
            loop(j, 1, 5) cin >> arr[i][j];

        // init: dp[1][2], dp[1][3], dp[1][4]
        loop(k, 2, 4)
            if(arr[1][k] != 1) dp[1][k] = getObstacle(1, k) + arr[1][k];

        loop(i, 2, n) loop(j, 1, 5) {
            if(arr[i][j] != 1) dp[i][j] = getObstacle(i, j) + arr[i][j];
            else continue;
            dp[i][j] += max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1]));
        }
        
        int ans = 0;
        loop(k, 1, 5) ans = max(ans, dp[n][k]);

        cout << ans << '\n';
    }
}