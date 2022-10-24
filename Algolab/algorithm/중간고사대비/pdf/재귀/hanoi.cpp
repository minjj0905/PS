#include <iostream>
using namespace std;

int cnt;

void hanoi(int n, int a, int b, int c) {
    if (n>0) {
        hanoi(n-1, a, c, b);
        cout << "Move " << a << " to " << b << "\n";
        cnt++;
        hanoi(n-1, b, a, c);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        cnt = 0;
        int n; cin >> n;
        hanoi(n, 1, 2, 3);
        cout << cnt << "\n";
    }
}