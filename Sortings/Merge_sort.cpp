/**
 *    author:  _Berlin_
 *    created: 26.06.2024 01:16:44 PM
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void merge(vector<int> &a, int lo, int mid, int hi) {
  vector<int> temp;
  int left = lo;
  int right = mid + 1;

  while(left <= mid && right <= hi) {
    if(a[left] <= a[right]) {
      temp.push_back(a[left]);
      left++;
    } else {
      temp.push_back(a[right]);
      right++;
    }
  }

  while(left <= mid) {
    temp.push_back(a[left]);
    left++;
  }

  while(right <= hi) {
    temp.push_back(a[right]);
    right++;
  }

  for(int i = lo; i <= hi; i++) {
    a[i] = temp[i - lo];
  }
}

void merge_sort(vector<int> &a, int lo, int hi) {
  if(lo >= hi) {
    return;
  }
  int mid = (lo + hi) / 2;
  merge_sort(a, lo, mid);
  merge_sort(a, mid + 1, hi);
  merge(a, lo, mid, hi);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> a = {9, 8, 7, 6, 5, 4, 3, 2, 1};

  int n = a.size();

  merge_sort(a, 0, n - 1);

  for(int i = 0; i < n; i++){
    cout << a[i] << " \n"[i == n - 1];
  }

  return 0;
}

/**
-Time Complexity:
  -Best Case: O(nlogn)
  -Average Case: O(nlogn)
  -Worst Case: O(nlogn)

-Space Complexity: O(n)
**/