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
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size(), n = mat[0].size();
    if (m * n != r * c) return mat;
    if (m == r && n == c) return mat;

    vector<vector<int>> newMat(r, vector<int>(c));
    for (int i = 0; i < m * n; i++) {
      newMat[i / c][i % c] = mat[i / n][i % n];
    }
    return newMat;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<vector<int>>> testMats = {{{1, 2}, {3, 4}}, {{1, 2}, {3, 4}}};
  vector<int> testRows = {1, 2};
  vector<int> testCols = {4, 4};
  size_t nTest = testMats.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "mat = " << int2dVectorToString(testMats[i])
         << ", r = " << testRows[i] << ", c = " << testCols[i] << endl;
    // Call the Solution function here!
    vector<vector<int>> newMat =
        Solution().matrixReshape(testMats[i], testRows[i], testCols[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(newMat) << endl;
    cout << "===========" << endl;
  }
}
