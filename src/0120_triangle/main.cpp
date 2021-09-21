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
  int minimumTotal(vector<vector<int>>& triangle) {
    int height = triangle.size(), dp[height];

    // copy the final layer
    for (int i = 0; i < height; i++) dp[i] = triangle[height - 1][i];

    for (int h = height - 2; h >= 0; h--) {
      for (int j = 0; j <= h; j++) {
        // we don't need other space to store the result of `h` layer
        dp[j] = min(dp[j], dp[j + 1]) + triangle[h][j];
      }
    }

    return dp[0];
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<vector<int>>> testTriangle = {
      {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, {{-10}}};
  size_t nTest = testTriangle.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "triangle = " << int2dVectorToString(testTriangle[i]) << endl;
    // Call the Solution function here!
    int res = Solution().minimumTotal(testTriangle[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
