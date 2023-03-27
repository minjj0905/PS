#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string isSame(string s1, string s2) {
    if(s1.size() != s2.size()) {
        return "different";
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2 ? "same" : "different";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;

    while(true) {
        string s1, s2;
        cin >> s1 >> s2;

        if(s1 == "END" && s2 == "END") break;

        cout << "Case " << tc << ": " << isSame(s1, s2) + "\n";
        tc++;
    }
}