#include <iostream>
using namespace std;
#define ull unsigned long long

pair<int, int> gettwo(int arr[], int low, int high) {
    if(low == high) return {arr[low], arr[low]};
    if(low+1 == high) {
        if(arr[low] > arr[high]) return {arr[low], arr[high]};
        else return {arr[high], arr[low]};
    }
    int mid = (low+high) /2;
    pair<int, int> left = gettwo(arr, low, mid);
    pair<int, int> right = gettwo(arr, mid+1, high);

    if(left.first > right.first) {
        if(left.second > right.first) return {left.first, left.second};
        else return {left.first, right.first};
    } else {
        if(right.second > left.first) return {right.first, right.second};
        else return {right.first, left.first};
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
        cout << gettwo(arr, 0, n-1).second << "\n";
    }
}