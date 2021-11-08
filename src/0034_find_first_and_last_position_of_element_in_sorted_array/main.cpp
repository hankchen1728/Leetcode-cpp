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
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1};

    int L = 0, R = nums.size() - 1, C;
    vector<int> res(2, -1);

    // Search the left (starting) position
    while (L < R) {
      C = (L + R) / 2;
      if (nums[C] < target) {
        L = C + 1;
      } else {
        R = C;
      }
    }

    // if target is not in the array
    if (nums[L] != target) {
      return res;
    } else {
      res[0] = L;
    }

    R = nums.size() - 1;
    // Search the right (ending) position
    while (L < R) {
      // Avoid Obsessed with the case L + 1 == R
      C = (L + R + 1) / 2;
      if (nums[C] > target) {
        R = C - 1;
      } else {
        L = C;
      }
    }
    res[1] = R;

    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {{5, 7, 7, 8, 8, 10}, {5, 7, 7, 8, 8, 10}, {}};
  vector<int> testTargets = {8, 6, 0};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testNums[i])
         << ", target = " << testTargets[i] << endl;
    // Call the Solution function here!
    vector<int> res = Solution().searchRange(testNums[i], testTargets[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
