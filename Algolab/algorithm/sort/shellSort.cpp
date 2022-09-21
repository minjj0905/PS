#include <iostream>
using namespace std;

#define MAX_SIZE 1000

void ShellSort(int a[], int n) {
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수

  int shrinkRatio = 2;
  int gap = n / shrinkRatio;
  int tmp, i, j;

  while( gap > 0 ) {
    for(i = gap; i < n; i++) {
      tmp = a[i];

      for(j = i; j >= gap; j -= gap ) {
        countCmpOps++;
        if((a[j - gap] < tmp)) break;
        countSwaps++;
        a[j] = a[j - gap];
      }

      a[j] = tmp;
    }
    gap /= shrinkRatio;
  }
  
  cout << countCmpOps << " " << countSwaps << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;

    while(tc--) {
      int num;
      int arr[MAX_SIZE];

      cin >> num;
      for(int i=0; i<num; i++) {
        cin >> arr[i];
      }

      ShellSort(arr, num);
    }
}