#include <bits/stdc++.h>

#define for1(s,n) for(int i = s; i < n; i++)
#define for1j(s,n) for(int j = s; j < n; j++)

using namespace std;
typedef long long ll;
typedef vector <ll> llv1;

ll tc, N;
ll ar[110][10];
ll score[110][10];

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  cin >> tc;
  while(tc--) {
    cin >> N;

    for(int i = 0; i < N + 1; i++) {
      for(int j = 0; j < 10; j++) {
        score[i][j] = 0;
      }
    }

    for(int i = N; i >= 1; i--) {
      for1j(1, 6) {
        cin >> ar[i][j];
      }
    }

    for(int i =1; i < N + 1; i++) {
      for(int j = 1; j < 6; j++) {
        ll parent_val = score[i - 1][j];
        ll parent = ar[i - 1][j];

        if(parent_val < score[i - 1][j - 1]) {
          parent_val = score[i - 1][j - 1];
          parent = ar[i - 1][j - 1];
        }

        if(parent_val < score[i - 1][j + 1]) {
          parent_val = score[i - 1][j + 1];
          parent = ar[i - 1][j + 1];
        }

        if(parent == 1) continue;

        score[i][j] = parent_val;

        if(ar[i][j] == 1) {
          score[i][j] = 0;
        }
        else {
          if(ar[i][j - 1] == 1) score[i][j]++;
          if(ar[i][j + 1] == 1) score[i][j]++;

          if(ar[i][j] > 1) {
            score[i][j] += ar[i][j];
          }
        }
      }
    }

    ll ans = 0;
    for(int i = 1; i < 6; i++) {
      ans = max(ans, score[N][i]);
    }
    cout << ans << "\n";
  }
}