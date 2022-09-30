#include <iostream>
using namespace std;

void swap(char& a, char& b);
int pow(int n, int e);
int getWeight(char* s);
void permutation(char* s, int depth, int size);
int strlen(char* arr);

int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
      cnt = 0;
      char str[9];
      cin >> str;
      permutation(str, 0, strlen(str));
      cout << cnt << "\n";
    }
}

int pow(int n, int e) {
  if(e == 0) return 1;
  int res = n;
  for(int i=0; i<e-1; i++) {
    res *= n;
  }
  return res;
}

int strlen(char* arr) {
  int cnt = 0;
  int idx = 0;
  while(1) {
    if(arr[idx] == '\0') {
      break;
    }
    else {
      cnt++;
    }
    idx++;
  }
  return cnt;
}

int getWeight(char* s) {
  int weight = 0;
  for(int i=0; i<strlen(s); i++) {
    weight += pow(-1, i)*(s[i] - 97);
  }
  return weight;
}

void swap(char& a, char& b) {
  char temp = a;
  a = b;
  b = temp;
}

void permutation(char* s, int depth, int size) {
  if (depth == size) {
    if(getWeight(s) > 0) {
      cnt++;
    }
  }

  for(int i= depth; i<size; i++) {
    swap(s[depth], s[i]);
    permutation(s, depth+1, size);
    swap(s[depth], s[i]);
  }
}