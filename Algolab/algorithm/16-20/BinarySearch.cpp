#include <iostream>
using namespace std;

#define MAX_SIZE 100

int search(int a[], int left, int right, int value) {
    if (left > right) return -1;

    int mid = (left+right)/2;
    if (a[mid] == value) return mid;
    else if (a[mid] > value) return search(a, left, mid-1, value);
    else return search(a, mid+1, right, value);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n, k, arr[MAX_SIZE]; cin >> n >> k;
        for(int i=0; i<n; i++) cin >> arr[i];

        cout << search(arr, 0, n-1, k) << "\n";
    }
}