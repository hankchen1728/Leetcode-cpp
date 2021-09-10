#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    // The algorithm
    int lPtr = 0, rPtr = nums.size() - 1;
    int center;

    while (lPtr <= rPtr) {
      center = (rPtr + lPtr) / 2;

      if (nums[center] > target) {
        rPtr = center - 1;
      } else if (nums[center] < target) {
        lPtr = center + 1;
      } else
        return center;
    }
    return -1;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {
      {-1, 0, 3, 5, 9, 12},
      {-1, 0, 3, 5, 9, 12},
      {-1, 0, 3, 5, 9, 12},
      {-1, 0, 3, 5, 9, 12}
  };
  vector<int> testTargets = {9, 2, -1, 12};
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
    int idx = Solution().search(testNums[i], testTargets[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << idx << endl;
    cout << "===========" << endl;
  }
}
