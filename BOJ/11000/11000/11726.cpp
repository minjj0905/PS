#include <iostream>
#include <vector>
#include <algorithm>

#define ull unsigned long long
#define mod 10007

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    int dp[1001];
    dp[0] = 0, dp[1] = 1, dp[2] = 2;
    for(int i=3; i<= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    cout << dp[n] % mod << "\n";
}