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
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int& num : nums) res ^= num;
    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {{2, 2, 1}, {4, 1, 2, 1, 2}, {1}};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums = " << intVectorToString(testNums[i]) << endl;
    // Call the Solution function here!
    int res = Solution().singleNumber(testNums[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
