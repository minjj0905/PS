#include <iostream>
using namespace std;

#define ull unsigned long long
#define MAX_SIZE 101
#define MAX(a,b) (a > b ? a : b)

int findMax(int arr[], int left, int right) {
    if(left >= right) return arr[left];

    int mid = (left+right)/2;
    return MAX(findMax(arr, left, mid), findMax(arr, mid+1, right));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >>n;
        int arr[MAX_SIZE];
        for(int i=0; i<n; i++) cin >> arr[i];

        cout << findMax(arr, 0, n-1) << "\n";
    }
}