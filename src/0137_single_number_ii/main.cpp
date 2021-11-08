#include <cstring>
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

    for (int iBit = 0; iBit < 32; iBit++) {
      int bitSum = 0;
      for (int& n : nums) {
        bitSum += (n >> iBit) & 1;
      }

      // if (bitSum % 3) res += (1 << iBit);
      res |= (bitSum % 3) << iBit;
    }
    return res;
  }
};
// Solution end

int main() {
  // Write something here
  vector<vector<int>> testNums = {
      {2, 2, 3, 2}, {0, 1, 0, 1, 0, 1, 99}, {15, 16, 17, 15, 16, 15, 16}};
  size_t nTest = testNums.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testNums[i]) << endl;
    // Call the Solution function here!
    int res = Solution().singleNumber(testNums[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
