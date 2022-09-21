#include <iostream>
using namespace std;

#define MAX_SIZE 1000

void combSort(int a[], int n) {
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수

  const double shrink = 1.3;
  int j, tmp, gap = n, swapped = 1;
 
  while(gap > 1 || swapped)
  {
    if ((gap/=shrink) < 1) gap = 1;
    for(j = swapped = 0; j < n-gap; j++)
    {
      countCmpOps++;
      if (a[j] <= a[j+gap]) continue;
     
      swapped = 1;
      countSwaps++;
      tmp = a[j]; a[j] = a[j+gap]; a[j+gap] = tmp;
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

      combSort(arr, num);
    }
}