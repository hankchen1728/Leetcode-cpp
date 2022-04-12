#include <iostream>
#include <vector>

#include "myUtils.h"

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

  bool isPerfectSquare(int num) {
    if (num == 1) return true;

    int L = 1, R = num / 2, mid, frac;

    while (L < R) {
      mid = L + (R - L + 1) / 2;
      frac = num / mid;

      if (frac > mid) {
        L = mid;
      } else if (frac < mid) {
        R = mid - 1;
      } else {
        return mid * mid == num ? true : false;
      }
    }

    return false;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<int> testCase = {
      16,  // true
      14,  // false
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m num = " << testCase[i] << endl;
    // Call the Solution function here!
    bool res = Solution().isPerfectSquare(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << BOOL2STR(res) << endl;
    cout << "===========" << endl;
  }
}
