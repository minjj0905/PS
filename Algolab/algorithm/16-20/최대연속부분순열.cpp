#include <iostream>
using namespace std;

#define MAX_SIZE 100
#define MAX(a,b) ((a)>(b)?(a):(b))

int max(int a[], int left, int right) {
    if (left == right) return a[left];

    int mid = (left+right) / 2;
    int leftMax = max(a, left, mid);
    int rightMax = max(a, mid+1, right);
    
    int res = MAX(leftMax, rightMax);
    int leftValue = 0, rightValue = 0, tmp = 0;

    for(int i=mid; i >= left; i--) {
        tmp += a[i];
        leftValue = MAX(leftValue, tmp);
    }

    tmp = 0;
    for(int i=mid+1; i<=right; i++) {
        tmp += a[i];
        rightValue = MAX(rightValue, tmp);
    }

    res = MAX(res, leftValue+rightValue);

    return res > 0 ? res : 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n, arr[MAX_SIZE]; cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];

        cout << max(arr, 0, n-1) << "\n";
    }
}