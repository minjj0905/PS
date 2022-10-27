#include <iostream>
using namespace std;

#define ull unsigned long long
#define MAX(a,b) (a > b ? a : b)

int findpeak(int arr[], int left, int right) {
    if (left > right) return -1;
    int mid = (left+right)/2;
    int leftMax = findpeak(arr, left, mid-1);
    int rightMax = findpeak(arr, mid+1, right);

    return MAX(MAX(arr[mid], leftMax), rightMax);
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

        cout << findpeak(arr, 0, n-1) << "\n";
    }
}