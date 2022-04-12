#include <iostream>
#include <vector>

#include "myUtils.h"

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
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    vector<vector<int>> res(grid);
    int8_t M = grid.size(), N = grid[0].size();
    int16_t MN = (int16_t)M * (int16_t)N;

    k %= (M * N);
    if (k == 0) return res;

    for (int8_t i = 0; i < M; ++i) {
      for (int8_t j = 0; j < N; ++j) {
        res[k / N][k % N] = grid[i][j];
        (++k) %= MN;
      }
    }

    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<pair<vector<vector<int>>, int>> testCase = {
      {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 1},  // [[9,1,2],[3,4,5],[6,7,8]]
      {{{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}},
       4},  // [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
      {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 9},  // [[1,2,3],[4,5,6],[7,8,9]]
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:\e[0m " << endl;
    printf("grid = %s, k = %d\n",
           int2dVectorToString(testCase[i].first).c_str(), testCase[i].second);
    // Call the Solution function here!
    vector<vector<int>> res =
        Solution().shiftGrid(testCase[i].first, testCase[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
