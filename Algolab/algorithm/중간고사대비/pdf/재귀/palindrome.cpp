#include <iostream>
using namespace std;

#define MAX_LENGTH 100

int strlen(char* arr) {
    int cnt = 0;
    int idx = 0;
    while(1) {
        if(arr[idx] == '\0') break;
        else cnt++;
        idx++;
    }
    return cnt;
}

int palindrome(char* str, int start, int end) {
    if(start >= end) return 1;
    if(str[start] != str[end]) return 0;
    return palindrome(str, start+1, end-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        char str[MAX_LENGTH];
        cin >> str;
        cout << palindrome(str, 0, strlen(str)-1) << "\n";
    }
}