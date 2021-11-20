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
  int singleNonDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      // get the neighbor element
      // if `mid` is 5, then get 4
      // if `mid` is 2, then get 3
      int near = mid + ((mid % 2)? -1: 1);
      if (nums[mid] == nums[near]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return nums[left];
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {{1, 1, 2, 3, 3, 4, 4, 8, 8},
                                  {3, 3, 7, 7, 10, 11, 11}};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testNums[i]) << endl;
    // Call the Solution function here!
    int res = Solution().singleNonDuplicate(testNums[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
