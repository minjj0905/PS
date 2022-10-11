#include <iostream>
using namespace std;

#define MAX_SIZE 100
#define MAX(a,b) ((a)>(b)?(a):(b))

int max(int arr[], int left, int right) {
    if (left == right) return arr[left];

    int half = (left+right)/2;
    return MAX(max(arr, left, half), max(arr, half+1, right));
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