#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    string s, io;
    io = "IOI";
    
    cin >> s;
    int res = 0;
    int cnt = 0;

    for(int i=0; i<m; i++) {
        if(s[i] == 'I') {
            if(s.substr(i, 3) == io) {
                cnt++;
                i++;
            }
            else {
                if (cnt >= n) {
                    cnt += -n + 1;
                    res += cnt;
                }
                cnt = 0;
            }
        }
        else {
            if (cnt >= n) {
                cnt += -n + 1;
                res += cnt;
                }
            cnt = 0;
        }
    }
    cout << res << "\n";
}