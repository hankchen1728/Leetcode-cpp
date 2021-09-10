#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  Solution() {
    // Speedup
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int searchInsert(vector<int>& nums, int target) {
    int lPtr = 0, rPtr = nums.size() - 1, center;
    while (lPtr < rPtr) {
      center = lPtr + (rPtr - lPtr) / 2;
      if (nums[center] > target) {
        rPtr = center - 1;
      } else if (nums[center] < target) {
        lPtr = center + 1;
      } else
        return center;
    }
    return (nums[lPtr] >= target) ? lPtr : lPtr + 1;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {{1, 3, 5, 6}, {1, 3, 5, 6}, {1, 3, 5, 6},
                                  {1, 3, 5, 6}, {1},          {1}};
  vector<int> testTargets = {5, 2, 7, 0, 0, 1};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums = " << intVectorToString(testNums[i])
         << ", target = " << testTargets[i] << endl;
    // Call the Solution function here!
    int ans = Solution().searchInsert(testNums[i], testTargets[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
