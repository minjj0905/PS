#include <iostream>
#include <vector>
using namespace std;

string isAnagram(string s1, string s2) {
    vector<int> alpha(26);

    if(s1.size() != s2.size()) {
        return s1 + " & " + s2 + " are NOT anagrams.\n";
    }

    for(int i=0; i<s1.size(); i++) {
        alpha[s1[i] - 97]++; 
    }
    for(int i=0; i<s2.size(); i++) {
        if(--alpha[s2[i] - 97] < 0) {
            return s1 + " & " + s2 + " are NOT anagrams.\n";
        };
    }
    return s1 + " & " + s2 + " are anagrams.\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;
    
    while(tc--) {
        string s1, s2;
        cin >> s1 >> s2;

        cout << isAnagram(s1, s2);
    }
}