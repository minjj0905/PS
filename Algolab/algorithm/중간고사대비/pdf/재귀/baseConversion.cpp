#include <iostream>
using namespace std;

const char baseTable[17] = "0123456789abcdef";

void baseConversion(int n, int base) {
    if (n >= base) baseConversion(n/base, base);
    cout << baseTable[n%base];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n, base; cin >> n >> base;
        baseConversion(n, base);
        cout << "\n";
    }
}