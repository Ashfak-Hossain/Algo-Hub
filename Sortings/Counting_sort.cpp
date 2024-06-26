/**
 *    author:  _Berlin_
 *    created: 26.06.2024 11:13:02 PM
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

vector<int> countSort(vector<int>& a) {
  int n = a.size();
  int m = 0;
  for (int i = 0; i < n; i++) {
      m = max(m, a[i]);
  }
  vector<int> countArr(m + 1, 0);
  for (int i = 0; i < n; i++){
      countArr[a[i]]++;
  }
  for (int i = 1; i <= m; i++){
      countArr[i] += countArr[i - 1];
  }
  vector<int> outputArr(n);
  for (int i = n - 1; i >= 0; i--) {
      outputArr[countArr[a[i]] - 1] = a[i];
      countArr[a[i]]--;
  }
  return outputArr;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> a = {23, 34, 13, 1, 5, 78, 99};

  vector<int> sortedArr = countSort(a);

  for(int i = 0; i < a.size(); i++){
    cout << sortedArr[i] << " ";
  }

  return 0;
}

/**
-Time Complexity
    - Best Case: O(n + k)
    - Average Case: O(n + k)
    - Worst Case: O(n + k)

-Space Complexity: O(n + k)
**/