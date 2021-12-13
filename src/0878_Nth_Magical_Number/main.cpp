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

  // Greatest common factor of two number
  int gcd(int a, int b) {
    int residual;
    while (b > 0) {
      residual = a % b;
      a = b;
      b = residual;
    }
    return a;
  }

  int nthMagicalNumber(int n, int a, int b) {
    // find the least common multiple
    int lcm = a / gcd(a, b) * b;
    int nBase = lcm / a + lcm / b - 1;
    long res = (n / nBase) * (long)lcm % (int)(1e9 + 7);
    n %= nBase;

    if (n > 0) {
      // Binary Search
      int l = min(a, b), r = lcm - 1, mid;
      while (l < r) {
        mid = l + (r - l) / 2;
        if (mid / a + mid / b < n) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      res += l;
    }

    return res % (int)(1e9 + 7);
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {{1, 2, 3},
                                  {4, 2, 3},
                                  {5, 2, 4},
                                  {3, 6, 4},
                                  {(int)(1e7 + 7), 5324, 23238}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m n = " << testCase[i][0] << ", a = " << testCase[i][1]
         << ", b = " << testCase[i][2] << endl;
    // Call the Solution function here!
    int res = Solution().nthMagicalNumber(testCase[i][0], testCase[i][1],
                                          testCase[i][2]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
