#include <iostream>
using namespace std;

string s;
int t, score;

int main() {
    cin >> t;
    while(t--) {
        score = 0;
        cin >> s;
        int bf = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'O') {
                if(bf) {
                    bf += 1;
                    score += bf;
                }
                else {
                    score += 1;
                    bf = 1;
                }
            }
            else {
                bf = 0;
            }
        }
        cout << score << endl;
    }
}