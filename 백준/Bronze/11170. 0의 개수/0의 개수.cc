#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        int cnt = 0;
        for(int i=a; i<=b; i++) {
            string k = to_string(i);
            for(int j=0; j<k.size(); j++) {
                if(k[j] == '0') {
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }   
}