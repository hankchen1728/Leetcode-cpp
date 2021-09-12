#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    // The algorithm
    size_t len = nums.size();
    if (len < 3) return 0;

    // use array is faster than vector
    int diff[len];
    diff[0] = INT_MIN;
    // conti: length of current subarray which has
    // same consecutive differences for its all elements
    int ans = 0, conti = 0;

    // Run dynamic programming
    for (int i = 1; i < len; ++i) {
      diff[i] = nums[i] - nums[i - 1];
      if (diff[i] == diff[i - 1]) {
        conti++;
      } else
        conti = 1;

      if (conti >= 2) ans += (conti - 1);
    }
    return ans;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {{1, 2, 3, 4}, {1}};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums = " << intVectorToString(testNums[i]) << endl;
    // Call the Solution function here!
    int ans = Solution().numberOfArithmeticSlices(testNums[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
