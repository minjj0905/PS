#include <iostream>
using namespace std;

#define mod 1000

int pow(int x, int n) {
  int y;
  if(n == 0) return 1;

  if(n%2) {
    y = pow(x, (n-1)/2) % mod;
    return x*y*y;
  } 
  
  y = pow(x, n/2) % mod;
  return y*y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
      int a, n; cin >> a >> n;
      cout << pow(a, n) % mod << "\n";;
    }
}