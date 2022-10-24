#include <iostream>
using namespace std;

#define MAX_LENGTH 100

void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void permute(char* str, int begin, int end) {
    int range = end - begin;
    if(range == 1) cout << str << "\n";
    else {
        for(int i=0; i<range; i++) {
            swap(str[begin], str[begin+i]); //바꾸고
            permute(str, begin+1, end);
            swap(str[begin], str[begin+i]); //복원
        }
    }
}

int strlen(char* str) {
    int cnt = 0, idx = 0;
    while(1) {
        if(str[idx] == '\0') break;
        else cnt++;
        idx++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        char str[MAX_LENGTH];
        cin >> str;

        permute(str, 0, strlen(str));
    }
}