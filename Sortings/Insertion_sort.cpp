#include <bits/stdc++.h>

using namespace std;

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
  
void insertion_sort(int a[], int n) {
  for(int i = 0; i <= n - 1; i++) {
    int j = i;
    while(j > 0 && a[j - 1] > a[j]) {
        swap(a[j], a[j - 1]);
        j--;
    }
  }

  // Printing the sorted array
  for(int i = 0; i < n; i++){
    cout << a[i] << " \n"[i == n - 1];
  }
}


int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a[] = {12, 54, 23, 12, 2, 0, 10};

  int n = sizeof(a) / sizeof(a[0]);

  insertion_sort(a, n);

  return 0;
}


/**
Insertion Sort Algorithm

Time Complexity:
- Best Case: O(n)
  - When the array is already sorted, the algorithm makes a single pass with no swaps.

- Average Case: O(n^2)
  - On average, the number of comparisons is proportional to n(n-1)/2.

- Worst Case: O(n^2)
    - When the array is sorted in reverse order, the algorithm performs n(n-1)/2 comparisons.

Space Complexity:
- O(1)
**/


