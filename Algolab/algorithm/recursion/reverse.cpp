#include <iostream>
using namespace std;

#define MAX_LENGTH 100

char e[1] = {""};

void reverse(char* s, int n);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
      char str[MAX_LENGTH] = {""};
      cin >> str;
      reverse(str, 99);
      cout << "\n";
    }
} 

void reverse(char* s, int n) {
  if(s[n] != e[0]) cout << s[n];
  if (n>0) reverse(s, n-1);
} 