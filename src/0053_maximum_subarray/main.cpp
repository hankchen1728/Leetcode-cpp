#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
      size_t len = nums.size();
      int maxSum,dp=maxSum=nums[0];

      for (size_t i=1; i<len; i++){
          dp = max(nums[i], dp + nums[i]);
          maxSum = max(maxSum, dp);
      }
      return maxSum;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testCase = {
      {-2, 1, -3, 4, -1, 2, 1, -5, 4}, {1}, {5, 4, -1, 7, 8}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int ans = Solution().maxSubArray(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
