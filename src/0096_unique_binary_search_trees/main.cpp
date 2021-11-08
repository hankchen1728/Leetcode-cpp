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
  int numTrees(int n) {
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[1] = dp[0] = 1;

    for (int l = 2; l <= n; l++) {
      for (int i = 0; i <= l - 1; i++) {
        dp[l] += dp[i] * dp[l - i - 1];
      }
    }
    return dp[n];
  }
};
// Solution end

int main() {
  // Write something here
  vector<int> testCase = {1, 2, 3};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    cout << "Input:"
         << "\e[0m n = " << testCase[i] << endl;
    // Call the Solution function here!
    int res = Solution().numTrees(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
