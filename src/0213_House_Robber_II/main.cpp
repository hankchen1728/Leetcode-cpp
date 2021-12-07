#include <algorithm>
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

  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int N = nums.size();
    // House[1]-House[n-1] and House[2]-House[n]
    return max(robHelper(nums, 0, N - 2), robHelper(nums, 1, N - 1));
  }

  int robHelper(vector<int>& nums, int L, int R) {
    if (R - L <= 1) return max(nums[L], nums[R]);

    int pprev = nums[L], prev = max(nums[L], nums[L + 1]), tmp;
    R = min((int)nums.size() - 1, R);

    // WARNING: please check R is smaller than size of the vector
    for (int i = L + 2; i <= R; i++) {
      tmp = prev;
      prev = max(prev, pprev + nums[i]);
      pprev = tmp;
    }
    return max(pprev, prev);
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testNums = {{2, 3, 2}, {1, 2, 3, 1}, {1, 2, 3}, {0, 0}};

  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testNums[i]) << endl;
    // Call the Solution function here!
    int res = Solution().rob(testNums[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
