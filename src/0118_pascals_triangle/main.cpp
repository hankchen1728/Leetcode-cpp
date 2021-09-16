#include <sys/_types/_size_t.h>

#include <cstddef>
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
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal(numRows);
    pascal[0] = {1};

    for (size_t row = 2; row <= numRows; row++) {
      pascal[row - 1].resize(row, 1);
      for (size_t i = 1; i < row - 1; i++) {
        pascal[row - 1][i] = pascal[row - 2][i - 1] + pascal[row - 2][i];
      }
    }
    return pascal;
  }
};
// Solution end

int main() {
  // Write something here
  vector<int> testCase = {5, 1};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "numRows = " << testCase[i] << endl;
    // Call the Solution function here!
    vector<vector<int>> ans = Solution().generate(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << int2dVectorToString(ans) << endl;
    cout << "===========" << endl;
  }
}
