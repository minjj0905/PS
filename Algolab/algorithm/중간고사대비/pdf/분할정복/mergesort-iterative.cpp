#include <iostream>
using namespace std;

#define ull unsigned long long
#define MAX_SIZE 100
#define MIN(a,b) (a<b ? a : b)

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

void mergesort(int arr[], int n) {
    int size = 1;
    while(size < n) {
        for(int i=0; i<n; i += 2*size) {
            int left = i;
            int mid = MIN(left+size-1, n-1);
            int right = MIN(i+2*size-1, n-1);

            merge(arr, left, mid, right);
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
        int n; cin >> n;
        int arr[MAX_SIZE];
        for(int i=0; i<n; i++) cin >> arr[i];
        cnt = 0;

        mergesort(arr, n);

        cout << cnt << "\n";
    }
}