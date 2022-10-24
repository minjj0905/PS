#include <iostream>

using namespace std;

int factorial(int n) {
    if(n <= 1) return n;
    return n*factorial(n-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        cout << factorial(n) << "\n";
    }
}