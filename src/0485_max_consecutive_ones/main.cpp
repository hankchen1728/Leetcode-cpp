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
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0, maxCnt = 0;
    for (int& num : nums) {
      if (num) {
        cnt++;
        if (cnt > maxCnt) maxCnt = cnt;
      } else {
        cnt = 0;
      }
    }
    return maxCnt;
  }
};
// Solution end

int main() {
  vector<vector<int>> testNums = {{1, 1, 0, 1, 1, 1}, {1, 0, 1, 1, 0, 1}};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m "
         << "nums = " << intVectorToString(testNums[i]) << endl;
    // Call the Solution function here!
    int res = Solution().findMaxConsecutiveOnes(testNums[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
