#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> answer;
    vector<int> v;
    for(int i=1; i<=n; i++) {
        v.push_back(i);
    }
    
    int idx = 1;
    int cnt = 0;
    while(cnt != n) {
        if(idx%k == 0) {
            answer.push_back(v[idx-1]);
            idx++;
            cnt++;
        }
        else {
            v.push_back(v[idx-1]);
            idx++;
        }
    }

    cout << "<";
    for(int i=0; i<answer.size()-1; i++) {
        cout << answer[i] << ", ";
    }
    cout << answer[answer.size()-1] << ">";

}