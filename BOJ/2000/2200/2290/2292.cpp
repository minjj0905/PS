#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    int cnt = 1;
    int room = 1;

    while(true) {
        if(n <= room ) {
            break;
        }
        else {
            cnt++;
            room += (cnt-1)*6;
        }
    }
    cout << cnt << "\n";
}