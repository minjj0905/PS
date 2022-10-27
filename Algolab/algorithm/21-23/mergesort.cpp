#include <iostream>

#define MAX_SIZE 100

using namespace std;

int cnt;

int MIN(int a, int b) {
    return a < b ? a : b;
}

void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int tmp[MAX_SIZE];
    for(i=low; i<=high; i++) tmp[i] = a[i];
    i = k = low;
    j = mid + 1;
    while(i<=mid && j<=high) {
        cnt++;
        if(tmp[i] <= tmp[j]) {
            a[k++] = tmp[i++];
        } else {
            a[k++] = tmp[j++];
        }
    }
    while(i<=mid) a[k++] = tmp[i++];
    while(j<=high) a[k++] = tmp[j++];
}

void mergesort(int arr[], int n) {
    int size = 1;
    while (size < n) {
        for(int i=0; i<n; i+=2*size) {
            int low = i;
            int mid = MIN(low+size-1, n-1);
            int high = MIN(i+2*size-1, n-1);

            merge(arr, low, mid, high);
        }
        size *= 2;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        cnt = 0;
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        mergesort(arr, n);
        cout << cnt << "\n";
    }
}