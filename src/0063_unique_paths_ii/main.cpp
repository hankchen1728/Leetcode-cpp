#include <cstring>
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
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;

    int dp[n];
    memset(dp, 0, sizeof(dp));
    // First row
    dp[0] = 1;
    for (int sc = 1; sc < n; sc++)
      dp[sc] = (obstacleGrid[0][sc] || dp[sc - 1] == 0) ? 0 : 1;

    for (int sr = 1; sr < m; sr++) {
      if (obstacleGrid[sr][0]) dp[0] = 0;
      for (int sc = 1; sc < n; sc++) {
        dp[sc] = (obstacleGrid[sr][sc]) ? 0 : dp[sc] + dp[sc - 1];
      }
    }
    return dp[n - 1];
  }
};
// Solution end

int main() {
  vector<vector<vector<int>>> testCase = {{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
                                          {{0, 1}, {0, 0}}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m obstacleGrid = " << int2dVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().uniquePathsWithObstacles(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
