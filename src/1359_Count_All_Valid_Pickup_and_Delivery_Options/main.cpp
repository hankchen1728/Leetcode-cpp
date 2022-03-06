#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
  typedef unsigned long long ULL;

 public:
  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  int countOrders(int n) {
    ULL res = 1;
    const int MOD = 1e9 + 7;

    for (int i = 2; i <= n; i++) {
      res = (res * (i * (2 * i - 1))) % MOD;
    }

    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<int> testCase = {1, 2, 3};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m n = " << testCase[i] << endl;
    // Call the Solution function here!
    int res = Solution().countOrders(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
