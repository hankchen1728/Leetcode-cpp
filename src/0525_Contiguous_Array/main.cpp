#include <iostream>
#include <unordered_map>
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
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> coord{{0, -1}};
    int diff = 0, res = 0;

    for (int i = 0; i < nums.size(); i++) {
      diff += nums[i] ? 1 : -1;
      if (coord.count(diff)) {
        res = max(res, i - coord[diff]);
      } else {
        coord[diff] = i;
      }
    }

    return res;
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {{0, 1}, {0, 1, 0}, {0, 1, 0, 0, 1, 0,0,0,0,0, 1,1}};
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().findMaxLength(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
