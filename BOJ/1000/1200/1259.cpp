#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while(true) {
      int n;
      cin >> n;
      if(!n) break; 

      string s = to_string(n);
      for(int i=0; i<s.size()/2+1; i++) {
        if (s[i] != s[s.size()-i-1]) {
          cout << "no" << "\n";
          break;
        }
        if (i == s.size()/2) {
          cout << "yes\n" ;
        }
      }
    }
}