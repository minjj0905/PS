#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    int t;
    cin >> s;
    cin >> t;

    while(t--) {
      int a, b;
      cin >> a >> b;
      swap(s[a], s[b]);
    }

    cout << s << "\n";;
}