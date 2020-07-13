#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
int arr[26];

int main() {
    cin >> s;

    for(int i=0; i<26; i++) {
        arr[i] = -1;
    }

    for(int i=0; i<s.size(); i++) {
        if(arr[s[i]-97] < 0) {
            arr[s[i]-97] = i;
        }
    }

    for(int i=0; i<26; i++) {
        cout << arr[i] << " ";
    }
}