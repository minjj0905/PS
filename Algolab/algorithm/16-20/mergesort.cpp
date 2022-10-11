#include <iostream>
using namespace std;

#define MAX_SIZE 100

int cnt;

void merge(int a[], int low, int mid, int high) {
    int i, j, k;
    int tmp[MAX_SIZE];

    for(i=low; i<=high; i++) tmp[i] = a[i];

    i = k = low;
    j = mid+1;
    
    while(i<=mid && j<=high) {
        cnt++;
        tmp[i] <= tmp[j] ? a[k++] = tmp[i++] : a[k++] = tmp[j++];
    }

    while(i<=mid) a[k++] = tmp[i++];
    while(j<=high) a[k++] = tmp[j++];
}

void mergeSort(int a[], int low, int high) {
    if(low == high) return;

    int mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid+1, high);
    merge(a, low, mid, high);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n, arr[MAX_SIZE]; cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        
        cnt = 0;
        mergeSort(arr, 0, n-1);
        cout << cnt << "\n";
    }
}