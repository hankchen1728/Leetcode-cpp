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
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int rows = matrix.size(), cols = matrix[0].size();
    if (target < matrix[0][0] || target > matrix[rows - 1][cols - 1])
      return false;

    int sr = 0, left = 0, right = cols - 1, center;

    // search the candidate row from all rows
    if (rows > 1) {
      while (target >= matrix[sr][0] && ++sr < rows) {}
      sr -= 1;
    }

    // Binray search the current row
    while (left <= right) {
      center = (left + right) / 2;
      if (target > matrix[sr][center]) {
        left = center + 1;
      } else if (target < matrix[sr][center]) {
        right = center - 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<vector<int>>> testMats = {
      {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}},
      {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}},
      {{1, 3}},
      {{1}, {3}},
      {{1}}};
  vector<int> testTargets = {3, 13, 2, 3, 1};
  size_t nTest = testMats.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "matrix = " << int2dVectorToString(testMats[i])
         << ", target = " << testTargets[i] << endl;
    // Call the Solution function here!
    bool res = Solution().searchMatrix(testMats[i], testTargets[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << (res ? "true" : "false") << endl;
    cout << "===========" << endl;
  }
}
