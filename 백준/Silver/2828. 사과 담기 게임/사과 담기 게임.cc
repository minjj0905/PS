#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, j;
    queue<int> apples;
    
    cin >> n >> m >> j;
    for(int i=0; i<j; i++) {
        int t;
        cin >> t;
        apples.push(t);
    }

    int x = 1;
    int d = 0;

    while(j--) {
        if((x <= apples.front()) && (x+m-1 >= apples.front())) {
            apples.pop();
        }
        else if(x > apples.front()) {d += x - apples.front();
            x = apples.front();
            apples.pop();
        }
        else if(x+m-1 < apples.front()) {
            d += apples.front() - (x+m-1);
            x = apples.front() - (m-1);
            apples.pop();
        }
    }

    cout << d;
}