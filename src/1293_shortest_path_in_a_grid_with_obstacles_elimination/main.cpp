#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    // <x, y, remain obstacle>
    queue<tuple<int, int, int>> cells({{0, 0, k}});

    vector<pair<int, int>> directions = {make_pair(0, 1), make_pair(1, 0),
                                         make_pair(0, -1), make_pair(-1, 0)};
    const int rows = grid.size(), cols = grid[0].size();

    // create a matrix for recordning
    // "lagerest" remain number of obstacles at each cell
    int visited[rows][cols];
    memset(visited, -1, sizeof(visited[0][0]) * rows * cols);
    visited[0][0] = k;

    int steps = 0,
        sr,     // y (row) coord of current cell
        sc,     // x (col) coord of current cell
        currR,  // remain obstacle of current cell
        nr,     // y (row) coord of current cell
        nc,     // x (col) coord of current cell
        nextR;  // remain obstacle of current cell
    while (!cells.empty()) {
      int nPos = cells.size();
      while (nPos-- > 0) {
        tie(sr, sc, currR) = cells.front();
        cells.pop();

        // if attach the end point (lower right corner)
        if (sr == rows - 1 && sc == cols - 1) return steps;

        for (pair<int, int>& direct : directions) {
          nr = sr + direct.first;
          nc = sc + direct.second;

          if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

          // go to next cell
          nextR = currR - grid[nr][nc];
          if (nextR > visited[nr][nc]) {
            // each value in `visited` are -1 at begin, if the condition hold
            // then `nextR` must be larger than or equal to 0
            // hence no need to check the value again
            visited[nr][nc] = nextR;
            cells.push({nr, nc, nextR});
          }
        }
      }
      steps++;
    }

    return -1;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<vector<int>>> testGrids = {
      {{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}},
      {{0, 1, 1}, {1, 1, 1}, {1, 0, 0}}};
  vector<int> testK = {1, 1, 1, 1, 5};
  size_t nTest = testGrids.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input: \e[0m\n"
         << "grid = \n"
         << int2dVectorToString(testGrids[i], true) << ",\nk = " << testK[i]
         << endl;
    // Call the Solution function here!
    int res = Solution().shortestPath(testGrids[i], testK[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
