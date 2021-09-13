#include <iostream>
#include <vector>

#include "../Utils/myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    if (nums.size() == 1) return;

    size_t nextZero = 0, len = nums.size();
    int temp;
    for (size_t pos = 0; pos < len; pos++) {
      if (nums[pos] != 0) {
        if (pos != nextZero) {
          // swap the element nums[pos] and nums[nextZero]
          temp = nums[pos];
          nums[pos] = nums[nextZero];
          nums[nextZero] = temp;
        }
        nextZero++;
      }
    }
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {
      {0, 1, 0, 3, 12}, {0}, {0, 0}, {-1, 0, 1, 0, 3, 0, 0, 5, 7}};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums = " << intVectorToString(testNums[i]) << endl;
    // Call the Solution function here!
    Solution().moveZeroes(testNums[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(testNums[i]) << endl;
    cout << "===========" << endl;
  }
}
