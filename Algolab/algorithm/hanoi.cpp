#include <iostream>
using namespace std;

int endTower[11];
int key = 0;
void hanoi(int n, int start, int end, int mid);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
      int n;
      cin >> n;
      for(int i=0; i<11; i++) endTower[i] = 0;
      key = 0;
      hanoi(n, 1, 2, 3);
      cout << "\n";
    }
}

void hanoi(int n, int start, int mid, int end) {
  if (n > 0) {
    hanoi(n-1, start, end, mid);
    if(end == 3) {
      endTower[++key] = n;
      cout << endTower[key] << ' ';
    } 
    else if (start == 3) {
      cout << endTower[--key] << ' ';
    }
    hanoi(n-1, mid, start, end);
  }
}
