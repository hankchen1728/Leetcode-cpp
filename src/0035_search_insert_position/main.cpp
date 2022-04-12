#include <iostream>
#include <vector>

#include "myUtils.h"

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
    int16_t L = 0, R = nums.size() - 1, mid;

    while (L < R) {
      mid = (L + R) / 2;
      if (nums[mid] > target) {
        R = mid - 1;
      } else if (nums[mid] < target) {
        L = mid + 1;
      } else {
        return mid;
      }
    }
    return nums[L] >= target ? L : L + 1;
  }
};
// Solution end

int main() {
  // Write something here
  vector<pair<vector<int>, int>> testCases = {
      {{1, 3, 5, 6}, 5},  // 2
      {{1, 3, 5, 6}, 2},  // 1
      {{1, 3, 5, 6}, 7},  // 4
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
    int ans = Solution().searchInsert(testCases[i].first, testCases[i].second);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << ans << endl;
    cout << "===========" << endl;
  }
}
