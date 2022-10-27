#include <bits/stdc++.h>

#define for1(s,n) for(int i = s; i < n; i++)
#define for1j(s,n) for(int j = s; j < n; j++)
#define foreach(k) for(auto i : k)
#define foreachj(k) for(auto j : k)
#define pb(a) push_back(a)
#define sz(a) a.size()

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef vector <int> iv1;
typedef vector <vector<int> > iv2;
typedef vector <ll> llv1;
typedef unsigned int uint;
typedef vector <ull> ullv1;
typedef vector <vector <ull> > ullv2;
typedef pair<ll, ll> pll;

ll tc; // 테스트케이스 수
ll n, m; // n: 안전지대 크기, m: 시간
ll poison_cnt; // 시체의 수
ll heal_cnt; // 치유와드의 수

vector<pll> poison;
vector<pll> heal;

int distance_poison(pll a, pll b) {
  return max(llabs(a.first - b.first), llabs(a.second - b.second));
}

int distance_heal(pll a, pll b) {
  return llabs(a.first - b.first) + llabs(a.second - b.second);
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  cin >> tc;

  while(tc--) {
    poison.clear();
    heal.clear();

    cin >> n >> m;

    cin >> poison_cnt >> heal_cnt;

    for(int i = 0; i < poison_cnt; i++) {
      ll x, y;
      cin >> x >> y;
      poison.push_back({ y, x });
    }

    for(int i = 0; i < heal_cnt; i++) {
      ll x, y;
      cin >> x >> y;
      heal.push_back({ y, x });
    }

    for(int y = 0; y < n; y++) {
      for(int x = 0; x < n; x++) {
        ll p = 0, h = 0;
        for(int i = 0; i < poison_cnt; i++) {
          ll dis = distance_poison({ x, y }, poison[i]);

          if(dis <= m) {
            p += dis == 0 ? m : m - dis + 1;
          }
        }

        for(int i = 0; i < heal_cnt; i++) {
          ll dis = distance_heal({ x, y }, heal[i]);

          if(dis <= m) {
            h += dis == 0 ? m : m - dis + 1;
          }
        }
        cout << h - p << " ";
      }
      cout << "\n";
    }
  }
}