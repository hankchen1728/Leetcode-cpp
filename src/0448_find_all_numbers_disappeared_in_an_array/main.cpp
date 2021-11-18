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
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int N = nums.size(), j;

    for (int i = 0; i < N; i++) {
      j = abs(nums[i]) - 1;
      nums[j] = -abs(nums[j]);
      // nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);

      // cout << "nums = " << intVectorToString(nums) << endl;
    }

    vector<int> res;
    for (int i = 1; i <= N; i++) {
      if (nums[i - 1] > 0) res.push_back(i);
    }

    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testCase = {{4, 3, 2, 7, 8, 2, 3, 1}, {1, 1}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    vector<int> res = Solution().findDisappearedNumbers(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << intVectorToString(res) << endl;
    cout << "===========" << endl;
  }
}
