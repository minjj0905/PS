#include <iostream>
using namespace std;

#define ull unsigned long long

int binarysearch(int arr[], int k, int left, int right) {
    if(left > right) return -1;
    
    int mid = (left+right)/2;

    if(k == arr[mid]) return mid; //중앙
    else if(k < arr[mid]) binarysearch(arr, k, left, mid-1); //왼쪽
    else binarysearch(arr, k, mid+1, right); //오른쪽
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n, k; cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];

        cout << binarysearch(arr, k, 0, n-1) << "\n";;
    }
}