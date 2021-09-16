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
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0, m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          int currArea = 0;
          areaDFS(grid, i, j, currArea, maxArea);
        }
      }
    }
    return maxArea;
  }

  void areaDFS(vector<vector<int>>& grid, int sr, int sc, int& currArea,
               int& maxArea) {
    int m = grid.size(), n = grid[0].size();
    if (sr < 0 || sc < 0 || sr >= m || sc >= n || grid[sr][sc] != 1) return;

    currArea++;

    // marked as visited
    grid[sr][sc] = 2;

    areaDFS(grid, sr - 1, sc, currArea, maxArea);
    areaDFS(grid, sr, sc - 1, currArea, maxArea);
    areaDFS(grid, sr + 1, sc, currArea, maxArea);
    areaDFS(grid, sr, sc + 1, currArea, maxArea);

    maxArea = max(maxArea, currArea);
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<vector<int>>> testGrids = {
      {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
       {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
       {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
       {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
       {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}},
      {{0, 0, 0, 0, 0, 0, 0, 0}}};
  size_t nTest = testGrids.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "grid = " << int2dVectorToString(testGrids[i]) << endl;
    // Call the Solution function here!
    int ans = Solution().maxAreaOfIsland(testGrids[i]);
    // cout << int2dVectorToString(testGrids[i]) << endl;
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
