#include <cstring>
#include <iostream>
#include <utility>
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
  int uniquePaths(int m, int n) {
    if (n > m) swap(m, n);

    int dp[n];
    memset(dp, 0, sizeof(dp));
    for (int sc = 0; sc < n; sc++) dp[sc] = 1;

    for (int sr = 1; sr < m; sr++) {
      for (int sc = 1; sc < n; sc++) {
        dp[sc] += dp[sc - 1];
      }
    }

    return dp[n - 1];
  }
};
// Solution end

int main() {
  // Write something here
  vector<pair<int, int>> testCase = {{3, 7}, {3, 2}, {1, 3}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m m = " << testCase[i].first << ", n = " << testCase[i].second
         << endl;
    // Call the Solution function here!
    int res = Solution().uniquePaths(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
