#include <iostream>
using namespace std;

int fibo(int n);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
      int n;
      cin >> n;
      cout << fibo(n) << "\n";
    }
}

int fibo(int n) {
  if(n == 0 || n == 1) return n;
  
  return fibo(n-1)+fibo(n-2);
}