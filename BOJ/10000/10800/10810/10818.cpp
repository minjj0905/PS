#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    cout << arr[0] << " " << arr[n-1] << endl;

}