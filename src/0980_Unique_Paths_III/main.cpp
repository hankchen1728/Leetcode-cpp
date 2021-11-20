#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int cnt = 0, M, N;

  Solution() {
    // Speed up
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }

  int uniquePathsIII(vector<vector<int>>& grid) {
    M = grid.size(), N = grid[0].size();
    int sx, sy, targetSteps = 0;

    // counting the number of non-obstacle square to walk over
    for (int sr = 0; sr < M; sr++) {
      for (int sc = 0; sc < N; sc++) {
        if (grid[sr][sc] == 0) {
          targetSteps++;
        } else if (grid[sr][sc] == 1) {
          sy = sr;
          sx = sc;
        }
      }
    }

    grid[sy][sx] = -1;
    DFS(sy - 1, sx, targetSteps, grid);
    DFS(sy, sx - 1, targetSteps, grid);
    DFS(sy + 1, sx, targetSteps, grid);
    DFS(sy, sx + 1, targetSteps, grid);

    return cnt;
  }

  void DFS(int sr, int sc, int& targetSteps, vector<vector<int>>& grid) {
    // out of scope or encounter obstacle
    if (sr < 0 || sr >= M || sc < 0 || sc >= N || grid[sr][sc] == -1) return;

    // Encounter the endpoint
    if (grid[sr][sc] == 2) {
      if (targetSteps == 0) cnt++;
      return;
    }

    if (grid[sr][sc] == 0) {
      targetSteps--;
      grid[sr][sc] = -1;
      DFS(sr - 1, sc, targetSteps, grid);
      DFS(sr, sc - 1, targetSteps, grid);
      DFS(sr + 1, sc, targetSteps, grid);
      DFS(sr, sc + 1, targetSteps, grid);
      grid[sr][sc] = 0;
      targetSteps++;
    }
    return;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<vector<int>>> testCase = {
      {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}},
      {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}},
      {{0, 1}, {2, 0}}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m grid = " << int2dVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().uniquePathsIII(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
