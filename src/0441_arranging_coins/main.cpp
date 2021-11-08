#include <algorithm>
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
  // Binary Search
  int arrangeCoins(int n) {
    long long int L = 0, R = min(65536, n), mid;
    while (L <= R) {
      mid = (L + R) / 2;
      if (mid * (mid + 1) / 2 > n) {
        R = mid - 1;
      } else {
        L = mid + 1;
      }
    }
    return R;
  }
};
// Solution end

int main() {
  // Write something here
  vector<int> testCase = {5, 8, 2147483647};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m n = " << testCase[i] << endl;
    // Call the Solution function here!
    int res = Solution().arrangeCoins(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
