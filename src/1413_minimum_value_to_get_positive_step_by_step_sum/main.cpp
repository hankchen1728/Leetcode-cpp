#include <algorithm>
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
  int minStartValue(vector<int>& nums) {
    int stepSum = 0, minSum = INT_MAX;

    for (int& n : nums) {
      stepSum += n;
      if (stepSum < minSum) {
        minSum = stepSum;
      }
    }
    return max(1 - minSum, 1);
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testCase = {{-3, 2, -3, 4, 2}, {1, 2}, {1, -2, -3}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().minStartValue(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
