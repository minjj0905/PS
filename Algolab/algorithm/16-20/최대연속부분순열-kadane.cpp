#include <iostream>
using namespace std;

#define MAX 100

int maxSubsequenceSum(int a[], int n, int *start, int *end) {
    int i, j;
    int maxSum = 0, thisSum = 0;

    *start = *end = -1;

    for(i=0, j=0; j<n; j++) {
        thisSum += a[j];

        if(thisSum > maxSum) {
            maxSum = thisSum;
            *start = a[i] ? i : ++i;
            *end = j;
        } else if (thisSum < 0) {
            i = j+1;
            thisSum = 0;
        }
    }

    if (!maxSum) *start = *end = -1;
    return maxSum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n, arr[MAX]; cin >> n;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        int start = -1, end = -1;
        cout << maxSubsequenceSum(arr, n, &start, &end) << ' '  << start << ' ' << end << "\n";;
    }
}