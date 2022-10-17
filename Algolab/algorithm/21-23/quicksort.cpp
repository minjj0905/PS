#include <iostream>
using namespace std;

int comp_hoare, comp_lumuto;
int swap_hoare, swap_lumuto;

void swap(int &a, int &b) {
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}

int partitionHoare(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    do {
        do {
            i++;
            comp_hoare++;
        } while(arr[i] < pivot);

        do {
            j--;
            comp_hoare++;
        } while(arr[j] > pivot);

        if (i<j) {
            swap_hoare++;
            swap(arr[i], arr[j]);
        } else {
            return j;
        }
    } while (true);
}

void quicksortHoare(int arr[], int low, int high) {
    if (low >= high) return;

    int p = partitionHoare(arr, low, high);
    quicksortHoare(arr, low, p);
    quicksortHoare(arr, p+1, high);
}

int partitionLumuto(int arr[], int low, int high) {
    int pivot = arr[low];
    int j = low;
    for (int i=low+1; i<=high; i++) {
        comp_lumuto++;
        if(arr[i] < pivot) {
            j++;
            swap_lumuto++;
            swap(arr[i], arr[j]);
        }
    }

    int pivot_pos = j;
    swap_lumuto++;
    swap(arr[pivot_pos], arr[low]);
    return pivot_pos;
}

void quicksortLumuto(int arr[], int low, int high) {
    if (low >= high) return;

    int p = partitionLumuto(arr, low, high);
    quicksortLumuto(arr, low, p-1);
    quicksortLumuto(arr, p+1, high);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        comp_hoare = 0, comp_lumuto = 0, swap_hoare = 0, swap_lumuto = 0;

        int n; cin >> n;
        int arr_h[n] = {0, };
        int arr_l[n] = {0, };
        for(int i=0; i<n; i++) {
            int a; cin >> a;
            arr_h[i] = arr_l[i] = a;
        }

        quicksortHoare(arr_h, 0, n-1);
        quicksortLumuto(arr_l, 0, n-1);
        cout << swap_hoare << " " << swap_lumuto << " " << comp_hoare << " " << comp_lumuto << "\n";
    }
}