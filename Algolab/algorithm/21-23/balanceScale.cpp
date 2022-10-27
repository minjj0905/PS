#include <iostream>
using namespace std;

int dp[10000000-1];
int MIN(int a, int b) {
    return a < b ? a : b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        
        int l = arr[0], r = arr[1];
        for(int i=2; i<n; i++) {
            if(l<=r) l += arr[i];
            else r += arr[i];
        }
        int diff = l>r ? l-r : r-l;
        for(int i=0; i<diff+1; i++) dp[i] = 999999;
        int weight[7] = {1, 2, 5, 10, 20, 50, 100};
        dp[0] = 0;
        for(int i=0; i<7; i++) {
            for(int j=weight[i]; j <= diff; j++) {
                dp[j] = MIN(dp[j], dp[j - weight[i]] + 1);
            }
        }
        cout << dp[diff] << "\n";

    }
}