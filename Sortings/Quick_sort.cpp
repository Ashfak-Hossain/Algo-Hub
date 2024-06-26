#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int lo, int hi) {
  int pivot = a[lo];
  int i = lo;
  int j = hi;

  while(i < j) {
    while(a[i] <= pivot && i <= hi - 1) {
      i++;
    }

    while(a[j] > pivot && j >= lo + 1) {
      j--;
    }

    if(i < j) {
      swap(a[i], a[j]);
    }
  }
  swap(a[lo], a[j]);
  return j;
}

void quick_sort(vector<int> &a, int lo, int hi) {
  if(lo < hi) {
    int pivotIndex = partition(a, lo, hi);
      quick_sort(a, lo, pivotIndex - 1);
      quick_sort(a, pivotIndex + 1, hi);
    }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> a = {90, 83, 23, 45, 65, 1, 5};
  int n = a.size();

  quick_sort(a, 0, n - 1);

  for(int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }

  return 0;
}

/**
-Time Complexity:
  -Best Case: O(nlogn)
  -Average Case: O(nlogn)
  -Worst Case: O(n^2)

-Space Complexity: O(1)
**/