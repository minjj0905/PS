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