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
  int deleteAndEarn(vector<int>& nums) {
    // create summation map
    unordered_map<uint16_t, int> mp;
    int maxN = nums[0], lastN = maxN;

    for (int& n : nums) {
      if (mp[n] == 0) {
        if (n > maxN)
          maxN = n;
        else if (n < lastN)
          lastN = n;
      }
      mp[n] += n;
    }

    for (uint16_t i = lastN + 1, lastlastN = lastN - 1; i <= maxN; ++i) {
      if (mp[i]) {
        mp[i] = (i - lastN == 1) ? max(mp[lastN], mp[lastlastN] + mp[i])
                                 : mp[lastN] + mp[i];
        lastlastN = lastN;
        lastN = i;
      }
    }

    return mp[maxN];
  }
};
// Solution end

int main() {
  // Setting the test cases
  vector<vector<int>> testCase = {
      {3, 4, 2},
      {2, 2, 3, 3, 3, 4},
  };
  size_t nTest = testCase.size();

  for (size_t i = 0; i < nTest; i++) {
    cout << "\e[1m"
         << "Example " << i + 1 << ":" << endl;
    // print the test case input here!
    cout << "Input:"
         << "\e[0m nums = " << intVectorToString(testCase[i]) << endl;
    // Call the Solution function here!
    int res = Solution().deleteAndEarn(testCase[i]);
    cout << "\e[1m"
         << "Output: "
         << "\e[0m " << res << endl;
    cout << "===========" << endl;
  }
}
