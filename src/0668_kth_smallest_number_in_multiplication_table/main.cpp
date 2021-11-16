#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  int findKthNumber(int m, int n, int k) {
    int left = 1, right = m * n, mid, cnt = 0;

    while (left < right) {
      mid = (left + right) / 2;
      cnt = 0;  // number of numbers lower than or equal to `mid`
                // i.e. `mid` can be considered as the `cnt`-th smallest number
      for (int i = 1; i <= m; i++) {
        cnt += (mid >= i * n) ? n : mid / i;
      }

      /**
       * another way to calculate `cnt`
       *
       * int sr = m, sc = 1;
       * while (sr >= 1 && sc <= n) {
       *   if (sr * sc > mid) sr = mid / sc;
       *   cnt += sr; sc++;
       * }
       */

      if (cnt >= k) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testCase = {{3, 3, 5}, {2, 3, 6}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m m = " << testCase[i][0] << ", n = " << testCase[i][1]
         << ", k = " << testCase[i][2] << endl;
    // Call the Solution function here!
    int res = Solution().findKthNumber(testCase[i][0], testCase[i][1],
                                        testCase[i][2]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
