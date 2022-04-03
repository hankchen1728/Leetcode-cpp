#include <algorithm>
#include <iostream>
#include <vector>

#include "myUtils.h"

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
  void nextPermutation(vector<int>& nums) {
    int8_t N = nums.size(), L = N - 2;

    // reverse the monotonic decreasing part from back
    while (L >= 0 && nums[L] >= nums[L + 1]) --L;
    if (nums[L + 1] > nums[N - 1]) {
      reverse(nums.begin() + L + 1, nums.end());
    }

    if (L >= 0) {
      // find first number larger than current peak number from the right side
      int8_t R = L + 1;
      while (nums[L] >= nums[R]) ++R;
      swap(nums[L], nums[R]);
    }

    return;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {
      {1, 2, 3},  // [1, 3, 2]
      {3, 2, 1},  // [1, 2, 3]
      {1, 1, 5},  // [1, 5, 1]
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    vector<int> res(testCase[i]);
    Solution().nextPermutation(res);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
