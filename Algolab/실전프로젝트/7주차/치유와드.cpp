#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        int a, b; cin >> a >> b;

        vector<pair<int, int>> poison;
        vector<pair<int, int>> heal;

        int p_map[22][22] = {0, };
        int h_map[22][22] = {0, };

        pair<int, int> rc;
        for(int i=0; i<a; i++) {
            cin >> rc.first >> rc.second;
            poison.push_back(rc);
        }

        for(int i=0; i<b; i++) {
             cin >> rc.first >> rc.second;
             heal.push_back(rc);
        }

        for(int t=1; t<=m; t++) {
            // 시체 와드 돌리기
            for(int p=0; p<a; p++) {
                for(int i=-t; i<=t; i++) {
                    for(int j=-t; j<=t; j++) {
                        if(poison[p].first + i >= 0 && poison[p].first + i < n && poison[p].second + j >= 0 && poison[p].second + j < n) {
                            p_map[poison[p].first + i][poison[p].second + j]--;
                        }
                    }
                }
            }

            // 치유 와드 돌리기
            for(int h=0; h<b; h++) {
                for(int i=-t; i<=0; i++) {
                    for(int j=-(i+t); j<=i+t; j++) {
                        if(heal[h].first + i >= 0 && heal[h].first + i < n && heal[h].second + j >= 0 && heal[h].second + j < n) {
                            h_map[heal[h].first + i][heal[h].second + j]++;
                        }
                    }
                }
                for(int i=1; i<=t; i++) {
                    for(int j=i-t; j<=t-i; j++) {
                        if(heal[h].first + i >= 0 && heal[h].first + i < n && heal[h].second + j >= 0 && heal[h].second + j < n) {
                            h_map[heal[h].first + i][heal[h].second + j]++;
                        }
                    }
                }
            }
            
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout << p_map[i][j]+h_map[i][j] << ' ';
            }
            cout << "\n";
        }

    }
}