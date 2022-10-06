#include <iostream>
#define ll long long int
#define SIZE 3
#define mod 1000
using namespace std;

ll fibo(ll n);

void multiply(ll a[SIZE][SIZE], ll b[SIZE][SIZE]);

ll ans[SIZE][SIZE] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
      ll n;
      cin >> n;
      cout << fibo(n) << "\n";
    }
}

ll fibo(ll n) {
    for(int i = 0; i < SIZE; i++) for(int j = 0; j < SIZE; j++) ans[i][j] = 0;
    for(ll i = 1; i < SIZE; i++) ans[i][i] = 1;

    ll a[SIZE][SIZE] = {0};

    a[1][1] = 1, a[1][2] = 1;
    a[2][1] = 1, a[2][2] = 0;

    while(n) {
        if(n % 2) multiply(ans, a);
        multiply(a, a); n /= 2;
    }

    return ans[1][2] % 1000;
}

void multiply(ll a[SIZE][SIZE], ll b[SIZE][SIZE]) {
    ll c[SIZE * 2][SIZE * 2] = {0};
    for(ll i = 1; i < SIZE; i++)
        for(ll j = 1; j < SIZE; j++)
            for(ll k = 1; k < SIZE; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;

    for(ll i = 1; i < SIZE; i++)
        for(ll j = 1; j < SIZE; j++)
            a[i][j] = c[i][j];
}