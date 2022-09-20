#include <iostream>
using namespace std;

#define MAX_SIZE 1000

void insertionSort(int a[], int n) {
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수
  
  int tmp, j;

  for(int i=1; i<n; i++) {
    tmp = a[i];

    
    for(j=i-1; j>=0; j--) {
      countCmpOps++;
      if(a[j]<=tmp) {
       break;
      } else {
      a[j+1] = a[j];
      countSwaps++;
      }
    }
    a[j+1] = tmp;
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
      insertionSort(arr, num);
    }
}