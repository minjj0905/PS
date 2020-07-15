#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, m;

int binarySearch(int s) {
    int start = 0;
    int end = n-1;
    int mid;
    
    while(end>=start) {
        mid = (start+end)/2;
        if(v[mid] == s) {
            return 1;
        }
        else if(v[mid] > s) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    cin >> m;

    for(int i=0; i<m; i++) {
        int n;
        cin >> n;
        cout << binarySearch(n) << "\n";
    }
}