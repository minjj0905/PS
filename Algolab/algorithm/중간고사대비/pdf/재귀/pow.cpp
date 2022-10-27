#include <iostream>
using namespace std;

int pow(int x, int n) {
    // O(n)
    if(n == 0) return 1;
    return x*pow(x, n-1);
}

int fastpow(int x, int n) {
    // O(log n)
    if(n==0) return 1;
    if(n&1) { //홀
        int p = fastpow(x, (n-1)/2);
        return x * p * p;
    } else { //짝
        int p = fastpow(x, (n)/2);
        return p * p;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int x, n; cin >> x >> n;

        cout << fastpow(x, n) << "\n";
    }
}