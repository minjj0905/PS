#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    for(int i=0; i<100; i++) {
        getline(cin, s);

        char alpabet[26] = {'E', 'P', 'L', 'R', 'A', 'G', 'F', 'S', 'O', 'X', 'V', 'C', 'W', 'T', 'I', 'B', 'Z', 'D', 'H', 'N', 'Y', 'K', 'M', 'J', 'U', 'Q'};
        vector<char> v;
        for(int i=0; i<s.size(); i++) {
            if(65<= s[i] && s[i] <= 90) {
                v.push_back(alpabet[s[i]-65]);
            }
            else if(97 <= s[i] && s[i] <= 122) {
                v.push_back(alpabet[s[i]-97]+32);
            }
            else {
                v.push_back(s[i]);
            }
        }

        string output(v.begin(), v.end());    
        cout << output << "\n";
    }
}