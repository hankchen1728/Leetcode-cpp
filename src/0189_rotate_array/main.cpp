#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    if (k % nums.size() == 0 || k == 0) return;

    size_t len = nums.size(), pos = 0, lastPos = 0;
    int tmp = nums[pos], poped;
    for (size_t numSwap = 0; numSwap < len; numSwap++) {
      pos = (pos + k) % len;
      poped = nums[pos];
      nums[pos] = tmp;
      tmp = poped;
      if (lastPos == pos) {
        pos = ++lastPos;
        tmp = nums[pos];
      }
    }
  }
};
// Solution end

int main() {
  // test cases
  vector<vector<int>> testNums = {
      {1, 2, 3, 4, 5, 6, 7}, {-1, -100, 3, 99}, {1, 2, 3, 4, 5, 6}};
  vector<int> testK = {3, 2, 4};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums = " << intVectorToString(testNums[i]) << ", k = " << testK[i]
         << endl;
    // Call the Solution function here!
    Solution().rotate(testNums[i], testK[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(testNums[i]) << endl;
    cout << "===========" << endl;
  }
}
