#include <iostream>
using namespace std;

#define ull unsigned long long

ull f[2][2] = {{1, 1}, {1, 0}};
ull m[2][2] = {{1, 1}, {1, 0}};

int fibonacci(int n) {
    // O(n)
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

void multifly(ull a[2][2], ull b[2][2]) {
    ull aa = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    ull bb = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    ull cc = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    ull dd = a[1][0]*b[0][1] + a[1][1]*b[1][1];

    a[0][0] = aa%1000; a[0][1] = bb%1000;
    a[1][0] = cc%1000; a[1][1] = dd%1000;
}

void pow(int n) {
    if(n<=1) return;
    pow(n/2);
    multifly(f, f);
    if(n&1) multifly(f, m);
}

int fastfibo(int n) {
    // O(log n)
    if(n==0) return 0;
    pow(n-1);
    return f[0][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        f[0][0] = 1, f[0][1] = 1;
        f[1][0] = 1, f[1][1] = 0;
        int n; cin >> n;
        cout << fastfibo(n) << "\n";
    }
}