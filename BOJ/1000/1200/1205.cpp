#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, score, p;
    cin >> n >> score >> p;

    vector<int> ranking(n);
    
    if (!n) {
        cout << "1\n";
        return 0;
    }

    for(int i=0; i<n; i++) {
        cin >> ranking[i];
    }

    sort(ranking.rbegin(), ranking.rend());

    if ((n == p) && (ranking.back() >= score)) {
        cout << "-1\n";
        return 0;
    }

    int r = 1;
    for(int i=0; i<n; i++) {
        if (ranking[i] > score) {
            r++;
        }
    }
    cout << r << '\n';

}
