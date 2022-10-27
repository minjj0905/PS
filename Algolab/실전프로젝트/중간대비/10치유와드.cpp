
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int tc;
int n, m;
int p_cnt, h_cnt;

vector<pll> poison;
vector<pll> heal;

ll distance_p(pll a, pll b) {
    return max(llabs(a.first - b.first), llabs(a.second - b.second));
}

ll distance_h(pll a, pll b) {
    return llabs(a.first - b.first) + llabs(a.second - b.second);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--) {
        poison.clear(); heal.clear();

        cin >> n >> m;
        cin >> p_cnt >> h_cnt;

        ll x, y;
        for(int i=0; i<p_cnt; i++) {
            cin >> x >> y;
            poison.push_back({y, x});
        }
        for(int i=0; i<h_cnt; i++) {
            cin >> x >> y;
            heal.push_back({y, x});
        }

        for(int y=0; y<n; y++) {
            for(int x=0; x<n; x++) {
                ll p = 0;
                ll h = 0;
                for(int i=0; i<p_cnt; i++) {
                    ll distance = distance_p({x, y}, poison[i]);
                    if(distance <= m) p += distance ? m - distance + 1 : m;
                }

                for(int i=0; i<h_cnt; i++) {
                    ll distance = distance_h({x, y}, heal[i]);
                    if(distance <= m) h += distance ? m - distance + 1 : m;
                }

                cout << h-p << ' ';
            }
            cout << '\n';
        }
    }
}