#include <algorithm>
#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    // Make the grids and then fill the 0's

    // vector<vector<int>> grid(n, vector<int>(n, INT_MAX));
    // using array is much faster
    int grid[n][n];
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) grid[i][j] = INT_MAX;
    }
    for (vector<int>& mine : mines) {
      grid[mine[0]][mine[1]] = 0;
    }

    int order = 0;
    for (size_t i = 0; i < n; i++) {
      int left = 0, right = 0, up = 0, down = 0;
      for (size_t j = 0; j < n; j++) {
        // left
        left = grid[i][j] ? left + 1 : 0;
        grid[i][j] = min(grid[i][j], left);

        // up
        up = grid[j][i] ? up + 1 : 0;
        grid[j][i] = min(grid[j][i], up);

        // right
        right = grid[i][n - j - 1] ? right + 1 : 0;
        grid[i][n - j - 1] = min(grid[i][n - j - 1], right);

        // down
        down = grid[n - j - 1][i] ? down + 1 : 0;
        grid[n - j - 1][i] = min(grid[n - j - 1][i], down);
      }
    }

    // Search the max value in the dynamic programming matrix
    for (auto const& row : grid) {
      // order = max(order, *max_element(row.begin(), row.end()));
      order = max(order, *max_element(row, row + n));
    }
    return order;
  }
};
// Solution end

int main() {
  // Write something here
  vector<int> testN = {5, 1, 3};
  vector<vector<vector<int>>> testMines = {{{4, 2}}, {{0, 0}}, {{0, 0}}};
  size_t nTest = testN.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1mExample " << i + 1 << ":" << endl;
    cout << "Input:\e[0m n = " << testN[i]
         << ", mines = " << int2dVectorToString(testMines[i]) << endl;
    int ans = Solution().orderOfLargestPlusSign(testN[i], testMines[i]);
    cout << "\e[1mOutput:\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
