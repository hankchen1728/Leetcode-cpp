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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> series(rows * cols);

    int nBound = min((rows + 1) / 2, (cols + 1) / 2);
    int r = 0, c = 0, iElem = 0;
    for (int it = 0; it < nBound; it++, rows -= 2, cols -= 2) {
      // top border
      for (c = it, r = it; c < it + cols; c++) {
        series[iElem++] = matrix[r][c];
      }

      // right border
      for (c = cols + it - 1, r = it + 1; r < rows + it; r++) {
        series[iElem++] = matrix[r][c];
      }

      if (rows == 1 || cols == 1) break;

      // bottom border
      for (c = it + cols - 2, r = rows + it - 1; c >= it; c--) {
        series[iElem++] = matrix[r][c];
      }

      // right border
      for (c = it, r = it + rows - 2; r > it; r--) {
        series[iElem++] = matrix[r][c];
      }
    }
    return series;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<vector<int>>> testMats = {
      {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
      {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
      {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}},
      {{6, 9, 7}},
      {{1}, {2}, {3}}};
  size_t nTest = testMats.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "matrix = " << int2dVectorToString(testMats[i]) << endl;
    // Call the Solution function here!
    vector<int> ans = Solution().spiralOrder(testMats[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(ans) << endl;
    cout << "===========" << endl;
  }
}
