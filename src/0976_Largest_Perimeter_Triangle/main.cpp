#include <algorithm>
#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    size_t idx = nums.size() - 1;

    while (idx >= 2 && nums[idx] >= nums[idx - 1] + nums[idx - 2]) --idx;

    return (idx < 2) ? 0 : nums[idx] + nums[idx - 1] + nums[idx - 2];
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {
      {2, 1, 2},  // 5
      {1, 2, 1},  // 0
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m " << endl;
    // Call the Solution function here!
    int res = Solution().largestPerimeter(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
