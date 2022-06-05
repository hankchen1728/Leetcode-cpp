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
  vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    uint16_t M = matrix.size(), N = matrix[0].size();
    vector<vector<int>> mT(N, vector<int>(M));

    for (uint16_t i = 0; i < M; ++i) {
      for (uint16_t j = 0; j < N; ++j) {
        mT[j][i] = matrix[i][j];
      }
    }
    return mT;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<vector<int>>> testCase = {
      {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},  // [[1,4,7],[2,5,8],[3,6,9]]
      {{1, 2, 3}, {4, 5, 6}},             // [[1,4],[2,5],[3,6]]
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m matrix = " << int2dVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    vector<vector<int>> res = Solution().transpose(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
