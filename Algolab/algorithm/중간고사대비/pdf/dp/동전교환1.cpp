#include <iostream>
using namespace std;
#define ull unsigned long long

int min(int a, int b) {
    return a < b ? a : b;
}

void reconstruct(int change, int lastCoin[]) {
    if (change > 0) {
        reconstruct(change-lastCoin[change], lastCoin);
        cout << lastCoin[change] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        
        int n; cin >> n;
        int coins[n];
        for(int i=0; i<n; i++) cin >> coins[i];
        int k; cin >> k;

        // pdf방법
        int coinUsed[101] = {0};
        int lastCoin[101] = {0};

       for(int cents=1; cents<=k; cents++) {
            int minCoins, newCoin;

            minCoins = cents;
            newCoin = 1;
            for(int i=0; i<n; i++) {
                if(coins[i] > cents) continue;
                if(coinUsed[cents - coins[i]] + 1 < minCoins) {
                    minCoins = coinUsed[cents-coins[i]] + 1;
                    newCoin = coins[i];
                }
            }

            coinUsed[cents] = minCoins;
            lastCoin[cents] = newCoin;
        }
        cout << coinUsed[k] << "\n";
        reconstruct(k, lastCoin);
        cout << "\n";
    }
}