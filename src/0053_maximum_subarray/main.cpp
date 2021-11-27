#include <climits>
#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    // Method 1: Dynamic Program
    size_t len = nums.size();
    int maxSum, dp = maxSum = nums[0];

    for (size_t i = 1; i < len; i++) {
      dp = max(nums[i], dp + nums[i]);
      maxSum = max(maxSum, dp);
    }
    return maxSum;

    // Method 2: Divide and Conquer
    // return mergeSum(nums, 0, nums.size() - 1);
  }

  // Helper function for Divide and Conquer approach
  int mergeSum(vector<int>& nums, int low, int high) {
    if (low == high) return nums[low];

    int mid = (low + high) / 2;
    return max({
        mergeSum(nums, low, mid),           // left half
        mergeSum(nums, mid + 1, high),      // right half
        middleCross(nums, low, mid, high),  // cross middle
    });
  }

  int middleCross(vector<int>& nums, int low, int mid, int high) {
    int subSum = 0, leftSum = INT_MIN, rightSum = INT_MIN;
    for (int i = mid; i >= low; i--) {
      subSum += nums[i];
      leftSum = max(subSum, leftSum);
    }
    subSum = 0;
    for (int i = mid + 1; i <= high; i++) {
      subSum += nums[i];
      rightSum = max(subSum, rightSum);
    }
    return leftSum + rightSum;
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
