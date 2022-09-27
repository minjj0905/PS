#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull factorial(ull n);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
      ull n;
      cin >> n;
      cout << factorial(n)%1000 << "\n";
    }
}

ull factorial(ull n) {
  if (n==0) return 1;
  ull res = n * factorial(n-1);
  while (res%10 == 0) res /= 10;
  res %= 100000;
  return res;
}