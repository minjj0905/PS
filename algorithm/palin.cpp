#include <iostream>
using namespace std;
#define ull unsigned long long

int palindrome(int* arr, int s, int e) {
    if(s >= e) return 1;
    if(arr[s] != arr[e]) return 0;
    return palindrome(arr, s+1, e-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];

        cout << palindrome(arr, 0, n-1) << "\n";;
    }
}