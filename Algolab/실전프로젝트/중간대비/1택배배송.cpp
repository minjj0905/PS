#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll tc;
ll N, M, A, B; // N : 도시 개수, M : 도로 개수
ll O, D, C;
ll ar[1100];

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  cin >> tc;

  while(tc--) {
    cin >> N >> M >> A >> B;
    fill(ar, ar+1050, 0);

    vector<pll> adj[1100];

    for(int i = 0; i < M; i++) {
      cin >> O >> D >> C;
      adj[O].push_back({ D, C });
      adj[D].push_back({ O, C });
    }

    queue <pll> Q;

    Q.push({ A, (ll)87654321 });

    while(!Q.empty()) {
      pll f = Q.front();
      Q.pop();

      if(ar[f.first] >= f.second) continue;

      ar[f.first] = f.second;


      for(pll edge : adj[f.first]) {
        if(ar[edge.first] < min(edge.second, f.second)) {
          Q.push({ edge.first, min(edge.second, f.second) });
        }
      }
    }

    cout << ar[B] << "\n";
  }
}