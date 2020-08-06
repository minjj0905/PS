#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isMinsu(string str) {
    for(int i=0; i<str.size(); i++) {
        if(str[i] != 52 && str[i] != 55) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for(int i=n; i>0; i--) {
        if(isMinsu(to_string(i))) {
            cout << i << "\n";
            break;
        }
    }
}