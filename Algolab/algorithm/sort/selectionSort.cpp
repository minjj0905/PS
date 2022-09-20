#include <iostream>
using namespace std;

#define MAX_SIZE 1000

void swap(int &a, int &b) {
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}

void selectionSort(int a[], int n) {
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수

  
  for(int i=0; i<n-1; i++) {
    int min = a[i];
    int idx = i;

    for(int j=i+1; j<n; j++) {
      countCmpOps++;
      if(a[j] < min) {
        min = a[j];
        idx = j;
      }
    }
    if(i != idx) {
      countSwaps++;
      swap(a[i], a[idx]);
    }
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

      selectionSort(arr, num);
    }
    
}


