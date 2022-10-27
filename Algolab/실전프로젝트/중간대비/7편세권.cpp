#include <iostream>
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
        int n, c_n; cin >> n >> c_n;
        int map[n][n] = {0};
        int con[c_n][2] = {0};
        fill(&map[0][0], &map[n-1][n-1], 0);

        for(int i=0; i<c_n; i++) {
            int r, c; cin >> r >> c;
            map[c][r] = -1;
            con[i][0] = c; con[i][1] = r;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(map[i][j] < 0) continue;

                int cur[2] = {i, j};
                for(int k=0; k<c_n; k++) {
                    int d = distance(cur, con[k]);
                    if(d <= 3) map[i][j] += 3;
                    else if (d <= 10) map[i][j] += 1;
                } 
            }
        }

        int max = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(map[i][j] > max) max = map[i][j];

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(map[j][i] == max) {
                    cout << i << ' ' << j << ' ' << max << '\n';
                    i+=n;
                    break;
                }
    }
}