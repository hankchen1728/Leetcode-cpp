#include <sys/_types/_size_t.h>

#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int len = nums.size();
    int l = 0, r = len - 1;

    vector<int> res(len);

    while (l <= r) {
      if (abs(nums[l]) > abs(nums[r])) {
        res[r - l] = nums[l] * nums[l];
        l++;
      } else {
        res[r - l] = nums[r] * nums[r];
        r--;
      }
    }
    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {
      {-4, -1, 0, 3, 10}, {-7, -3, 2, 3, 11}, {1}, {10000, 10000}};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums = " << intVectorToString(testNums[i]) << endl;
    // Call the Solution function here!
    vector<int> ans = Solution().sortedSquares(testNums[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(ans) << endl;
    cout << "===========" << endl;
  }
}
