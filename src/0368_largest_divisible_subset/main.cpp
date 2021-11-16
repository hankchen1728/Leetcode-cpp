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
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    // first sort the array
    int len = nums.size(), maxLen = 0, maxEnd = 0;
    sort(nums.begin(), nums.end());
    // length of longest subset
    vector<int> dp(len, 1);
    // last position of the current longest subset
    vector<int> lastIdx(len, -1);

    for (int i = 1; i < len; i++) {
      int subMax = 1;
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0 && dp[j] + 1 > subMax) {
          subMax = dp[j] + 1;
          lastIdx[i] = j;
        }
      }
      dp[i] = subMax;
      if (subMax > maxLen) {
        maxLen = subMax;
        maxEnd = i;
      }
    }

    vector<int> res;
    while (maxEnd >= 0) {
      res.insert(res.begin(), nums[maxEnd]);
      maxEnd = lastIdx[maxEnd];
    }
    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testCase = {{1, 2, 3}, {1, 2, 4, 8}, {1}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    vector<int> res = Solution().largestDivisibleSubset(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
