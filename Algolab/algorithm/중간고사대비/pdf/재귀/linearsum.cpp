#include <iostream>
using namespace std;

int linearSum(int a[], int n) {
    if(n==1) return a[0];
    return linearSum(a, n-1) + a[n-1];
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

        cout << linearSum(arr, n) << "\n";
    }
}