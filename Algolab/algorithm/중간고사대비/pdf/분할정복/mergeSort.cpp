#include <iostream>
using namespace std;

#define ull unsigned long long
#define MAX_SIZE 100

int cnt;

void merge(int arr[], int left, int mid, int right) {
    int tmp[MAX_SIZE];
    for(int i=left; i<=right; i++) tmp[i] = arr[i];

    int i, j, k;
    i = k = left;
    j = mid + 1;
    // i는 왼쪽 인덱스 j는 오른쪽인덱스 k는 전체 인덱스
    while(i <= mid && j <= right) {
        cnt++;
        if(tmp[i] <= tmp[j]) arr[k++] = tmp[i++]; //왼쪽 데이터가 더 작아서 넣는중
        else arr[k++] = tmp[j++]; //오른쪽 데이터가 작을경우에
    }
    while(i<=mid) arr[k++] = tmp[i++];
    while(j<=right) arr[k++] = tmp[j++];
}

void mergesort(int arr[], int left, int right) {
    if(left == right) return;
    
    int mid = (left+right)/2;
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int arr[MAX_SIZE];
        for(int i=0; i<n; i++) cin >> arr[i];
        cnt = 0;

        mergesort(arr, 0, n-1);

        cout << cnt << "\n";
    }
}