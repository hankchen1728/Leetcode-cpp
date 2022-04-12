#include <iostream>
#include <vector>

#include "myUtils.h"

using namespace std;

// Solution begin
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    // The algorithm
    int16_t L = 0, R = nums.size() - 1;
    int16_t mid;

    while (L <= R) {
      mid = (R + L) / 2;

      if (nums[mid] > target) {
        R = mid - 1;
      } else if (nums[mid] < target) {
        L = mid + 1;
      } else
        return (int)mid;
    }
    return -1;
  }
};
// Solution end

int main() {
  // Write something here
  vector<pair<vector<int>, int>> testCases = {
      {{-1, 0, 3, 5, 9, 12}, 9},  // 4
      {{-1, 0, 3, 5, 9, 12}, 2},  // -1
  };
  size_t nTest = testCases.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums = " << intVectorToString(testCases[i].first)
         << ", target = " << testCases[i].second << endl;
    // Call the Solution function here!
    int res = Solution().search(testCases[i].first, testCases[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
