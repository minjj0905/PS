#include <iostream>
#include <algorithm>
using namespace std;

int distance(int a[], int b[]) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        int a, b; cin >> a >> b;

        int map[n][n] = {0};
        fill(&map[0][0], &map[n-1][n-1], 0);
        int demage[a][2] = {0};
        int heal[b][2] = {0};

        for(int i=0; i<a; i++) {
           cin >> demage[i][1] >> demage[i][0];
        }
        
        for(int i=0; i<b; i++) {
            cin >> heal[i][1] >> heal[i][0];
        }


        for(int i=1; i<=m; i++) {
            for(int d=0; d<a; d++) {
                int d_r = demage[d][1];
                int d_c = demage[d][0];

                for(int r=-i; r<=i; r++) {
                    for(int c=-i; c<=i; c++) {
                        map[d_c + c -1][d_r + r -1] -= i;
                    }
                }
            }
            
            for(int h=0; h<b; h++) {
                int h_r = heal[h][1];
                int h_c = heal[h][0];

                for(int r=-i; r<=i; r++) {
                    for(int c=-i; c<=i; c++) {
                        int cur[2] = {h_c + c, h_r + r};
                        if(distance(heal[h], cur) <= i)
                            map[h_c + c -1][h_r + r -1] += i;
                    }
                }
            }
        }

        for(int r=0; r<n; r++) {
            for(int c=0; c<n; c++)
                cout << map[c][r] << ' ';
            cout << "\n";
        }
    }
}