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
  int rob(vector<int>& nums) {
    int nHouse = nums.size(), maxProfit[nHouse + 1];
    maxProfit[0] = 0;
    maxProfit[1] = nums[0];

    for (int i = 1; i < nHouse; i++) {
      maxProfit[i + 1] = max(maxProfit[i - 1] + nums[i], maxProfit[i]);
    }
    return maxProfit[nHouse];
  }

  // method 2
  int rob2(vector<int>& nums) {
    int nHouse = nums.size(), robAtOdd = 0, robAtEven = 0;

    for (int i = 0; i < nHouse; i++) {
      if (i % 2) {
        robAtOdd = max(robAtEven, robAtOdd + nums[i]);
      } else {
        robAtEven = max(robAtOdd, robAtEven + nums[i]);
      }
    }
    return max(robAtOdd, robAtEven);
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {{1, 2, 3, 1}, {2, 7, 9, 3, 1}};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums = " << intVectorToString(testNums[i]) << endl;
    // Call the Solution function here!
    int res = Solution().rob(testNums[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
