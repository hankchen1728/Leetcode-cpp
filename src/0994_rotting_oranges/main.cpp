#include <iostream>
#include <queue>
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
  int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> rotten;
    int numFresh = 0, rows = grid.size(), cols = grid[0].size();

    // first find all rotten orange
    for (int sr = 0; sr < rows; sr++) {
      for (int sc = 0; sc < cols; sc++) {
        if (grid[sr][sc] == 2) {
          rotten.push(make_pair(sr, sc));
        } else if (grid[sr][sc] == 1) {
          numFresh++;
        }
      }
    }
    // if no rotten oranges, return -1 if any fresh orange exists
    if (rotten.empty()) return (numFresh) ? -1 : 0;

    vector<vector<int>> directs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int sr, sc, rotTime = 0;
    pair<int, int> pos;
    // Run breadth-first search
    while (!rotten.empty() && numFresh > 0) {
      rotTime++;
      for (size_t i = rotten.size(); i > 0; i--) {
        pos = rotten.front();
        rotten.pop();

        for (vector<int>& direct : directs) {
          sr = pos.first + direct[0], sc = pos.second + direct[1];
          // check if out of valid range, or visited
          if (sr < 0 || sr >= rows || sc < 0 || sc >= cols ||
              grid[sr][sc] != 1) {
            continue;
          }
          grid[sr][sc] = 2;
          numFresh--;
          rotten.push(make_pair(sr, sc));
        }
      }
    }
    return (numFresh) ? -1 : rotTime;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<vector<int>>> testGrids = {{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}},
                                           {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}},
                                           {{0, 2}},
                                           {{0}}};
  size_t nTest = testGrids.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "grid = " << int2dVectorToString(testGrids[i]) << endl;
    // Call the Solution function here!
    int res = Solution().orangesRotting(testGrids[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
