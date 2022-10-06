#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
  	ios::sync_with_stdio(0);
  	cin.tie(0);
 	cout.tie(0);
  	int tc;
	cin >> tc;
  	while(tc--) {
    int a, b;
	cin >> a >> b;
    cout << gcd(a, b) << '\n';
  }
}

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}