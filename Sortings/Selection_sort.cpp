#include <bits/stdc++.h>

using namespace std;

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
  
void selection_sort(int a[], int n) {
  for(int i = 0; i < n - 1; i++) {
    int mini = i;
    for(int j = i + 1; j < n; j++) {
        if(a[j] < a[mini]) {
            mini = j;
        }
    }
    swap(a[i], a[mini]);
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

   selection_sort(a, n);

  return 0;
}


/**
Selection Sort Algorithm


Time Complexity:
- Best Case: O(n^2)
  - The number of comparisons is the same as the average case.

- Average Case: O(n^2)
  - The number of comparisons is (n^2 - n) / 2.

- Worst Case: O(n^2)
    - The number of comparisons is the same as the average case.

Space Complexity:
- O(1)
**/