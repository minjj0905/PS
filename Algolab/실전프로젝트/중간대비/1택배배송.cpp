#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll n, m, a, b;
ll o, d, c;
ll arr[1100];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc; cin >> tc;
  while(tc--) {
    cin >> n >> m >> a >> b;
    fill(arr, arr+1050, 0);
    vector<pll> adj[1100];

    for(int i = 0; i < m; i++) {
      cin >> o >> d >> c;
      adj[o].push_back({ d, c });
      adj[d].push_back({ o, c });
    }

    queue <pll> q;
    q.push({ a, (ll)0x7fffffff });

    while(!q.empty()) {
      pll f = q.front();
      q.pop();

      if(arr[f.first] >= f.second) continue;

      arr[f.first] = f.second;

      for(pll edge : adj[f.first]) {
        if(arr[edge.first] < min(edge.second, f.second)) {
          q.push({ edge.first, min(edge.second, f.second) });
        }
      }
    }
    cout << arr[b] << '\n';
  }
}