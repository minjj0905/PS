#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll getDistance(pair <ll, ll> a, pair <ll, ll> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll poisonEndT(pair <ll, ll> a, ll n) {
    ll m = 0;
    for(ll i=0; i<n; i+=n-1) {
        m = max(m, llabs(i-a.first));
        m = max(m, llabs(i-a.second));
    }

    return m;
}

ll healEndT(pair <ll, ll> a, ll n) {
    ll m = 0;
    for(ll i=0; i<n; i+=n-1) {
        for(ll j=0; j<n; j+=n-1) {
            m = max(m, getDistance(a, {i ,j}));
        }
    }

    return m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll tc; cin >> tc;
    while(tc--) {
        ll n, m; cin >> n >> m;
        ll a, b; cin >> a >> b;

        vector<pair<ll, ll>> poison;
        vector<pair<ll, ll>> heal;

        pair<ll, ll> rc;
        for(ll i=0; i<a; i++) {
            cin >> rc.first >> rc.second;
            poison.push_back(rc);
        }

        for(ll i=0; i<b; i++) {
             cin >> rc.first >> rc.second;
             heal.push_back(rc);
        }

        ll map[21][21] = {0};

        // 반복문 종료시점 구하기
        ll maxT = 0;
        for(ll i=0; i<a; i++) {
            maxT = max(maxT, poisonEndT(poison[i], n));
        }
        for(ll i=0; i<b; i++) {
            maxT = max(maxT, healEndT(heal[i], n));
        }
        
        for(ll t=1; t<=min(maxT, m); t++) {
            // 독
            for(ll aa=0; aa<a; aa++){
                for(ll i=-t; i<=t; i++) {
                    for(ll j=-t; j<=t; j++) {
                        ll x = poison[aa].first + i;
                        ll y = poison[aa].second + j;
                        if(x>=0 && x<n && y>=0 && y<n) {
                            map[x][y]--;
                        }
                    }
                }
            }

            // 치유
            for(ll bb=0; bb<b; bb++) {
                for(ll i=-t; i<=t; i++) {
                    if(i<=0) {
                        for(ll j=-(i+t); j<=i+t; j++) {
                            ll x = heal[bb].first + i;
                            ll y = heal[bb].second + j;
                            if(x>=0 && x<n && y>=0 && y<n) {
                                map[x][y]++;
                            }
                        }
                    } else {
                        for(ll j=i-t; j<=t-i; j++) {
                            ll x = heal[bb].first + i;
                            ll y = heal[bb].second + j;
                            if(x>=0 && x<n && y>=0 && y<n) {
                                map[x][y]++;
                            }
                        }
                    }
                }
            }
        }

        for(ll i=0; i<n; i++) {
            for(ll j=0; j<n; j++) {
                cout << map[i][j] << ' ';
            }
            cout << "\n";
        }
    }
}