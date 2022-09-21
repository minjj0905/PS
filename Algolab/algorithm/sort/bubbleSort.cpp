#include <iostream>
using namespace std;

#define MAX_SIZE 1000

void swap(int &a, int &b) {
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}

void bubbleSort(int a[], int n) {
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수

  int pass, i;

	for (pass = 1; pass < n; pass++) {
		for (i = 1; i <= n - pass; i++) {
      countCmpOps++;
			if (a[i] < a[i - 1]) {
        countSwaps++;
				swap(a[i], a[i - 1]);
			}
		}
	}
  
  cout << countCmpOps << " " << countSwaps << " ";
}

void bubbleSortImproved1(int a[], int n) {
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수

  int pass, i;
  bool swapped;

	for (pass = 1; pass < n; pass++) {
    swapped = false;
    
		for (i = 1; i <= n - pass; i++) {
      countCmpOps++;

			if (a[i] < a[i - 1]) {
        countSwaps++;

        swapped = true;
				swap(a[i], a[i - 1]);
			}
		}

    if(!swapped) break;
	}

  cout << countCmpOps << " " << countSwaps << " ";
}

void bubbleSortImproved2(int a[], int n) {
  int countCmpOps = 0; // 비교 연산자 실행 횟수
  int countSwaps = 0; // swap 함수 실행 횟수

  int i;
  int swappedPos, lastSwappedPos;

  lastSwappedPos = n;
	while (lastSwappedPos > 0) {
    swappedPos = 0;

		for (i = 1; i < lastSwappedPos; i++) {
      countCmpOps++;

			if (a[i] < a[i - 1]) {
        countSwaps++;
        swappedPos = i;
				swap(a[i], a[i - 1]);
			}
		}
    lastSwappedPos = swappedPos;
	}

  cout << countCmpOps << " " << countSwaps << "\n";
}

void copyArray(int a[], int b[], int n) {
  for (int i = 0; i < n; i++) a[i] = b[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc;
    cin >> tc;

    while(tc--) {
      int num;
      int origin[MAX_SIZE];
      int arr[MAX_SIZE];
      int arr1[MAX_SIZE];
      int arr2[MAX_SIZE];

      cin >> num;
      for(int i=0; i<num; i++) {
        cin >> origin[i];
      }

      copyArray(arr, origin, num);
      copyArray(arr1, origin, num);
      copyArray(arr2, origin, num);

      bubbleSort(arr, num);
      bubbleSortImproved1(arr1, num);
      bubbleSortImproved2(arr2, num);

    }
}