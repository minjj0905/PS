#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int coin[n];
    for(int i=0; i<n; i++) cin >> coin[i];

    vector<int> dp(k+1, 999999);
    dp[0] = 0;

    for(int i=0; i<n; i++) {
        for(int j=coin[i]; j<=k; j++) {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }
    int ans = dp[k] != 999999 ? dp[k] : -1;
    cout << ans;
}