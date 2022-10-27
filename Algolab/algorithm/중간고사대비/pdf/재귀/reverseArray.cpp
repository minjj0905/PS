#include <iostream>
using namespace std;

void swap(int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void reverseArray(int arr[], int i, int j) {
    if (i<j) {
        swap(arr, i, j);
        reverseArray(arr, i+1, j-1);
    }
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
        reverseArray(arr, 0, n-1);
        for(int i=0; i<n; i++) cout << arr[i] << " ";
        cout << "\n";
    }
}